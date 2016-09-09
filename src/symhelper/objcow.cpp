
/* 
 * EISSEC (Extracting Instruction Semantics via Symbolic Execution of Code
 * Generators) is a symbolic execution based system for automatically extracting
 * assembly to IR translators from code generators of modern compilers.
 * 
 * Copyright (C) 2012 - 2016 by Niranjan Hasabnis and R.Sekar in Secure Systems
 * Lab, Stony Brook University, Stony Brook, NY 11794.
 *
 * This program is free software; you can redistribute it and/or modify 
 * it under the terms of the GNU General Public License as published by 
 * the Free Software Foundation; either version 2 of the License, or 
 * (at your option) any later version. 
 *
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
 * GNU General Public License for more details. 
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program; if not, write to the Free Software 
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
 */

#include <iostream>
#include <unordered_map>
#include <objcow.h>
#include <sys/types.h>
#include <unistd.h>

extern "C" {
	#include <execinfo.h>
	#include "common.h"
	char **backtrace_symbolsnlines(void *const *buffer, int size);
	void print_measurements();
}

using namespace std;
uint64_t bpStackDepth = 0;

uint64_t g_bid = 1;
stack<BranchPoint*> g_bpstack;
typedef unordered_map<string, pair<uint64_t, uint64_t>> BpMap_t;
typedef unordered_map<uint64_t, unordered_map<uint64_t, uint64_t> > EdgeMap_t;
BpMap_t g_bpmap;
EdgeMap_t g_edgemap;

extern char gLoc[128];

BranchPoint::BranchPoint() : br_ar_lower_(0), br_ar_higher_(0), 
        br_arp_(0), br_gcount_(0), br_parent_(0)
{
    br_bid_ = g_bid++;
}

BranchPoint::~BranchPoint()
{
    if (br_arp_)
        free(br_arp_);

    UndoRecord::iterator i = br_urec_.begin();
    for(; i < br_urec_.end(); ++i)
        delete (*i);

    i = br_symmetarec_.begin();
    for(; i < br_symmetarec_.end(); ++i)
        delete (*i);
}

void BranchPoint::SnapshotStack(void* ar_lower, void* ar_higher)
{
    assert(ar_higher > ar_lower);
    br_ar_higher_ = ar_higher; br_ar_lower_ = ar_lower;
    uintptr_t size = (char*) br_ar_higher_ - (char*) br_ar_lower_;
    DEBUG_PRINTF("Saving AR for bid = %llu AR= [%p, %p] size = %u bytes", 
            br_bid_, br_ar_lower_, br_ar_higher_, size);
    assert((br_arp_ = (char*) malloc (size)) != NULL);
    memcpy (br_arp_, br_ar_lower_, size);

    // Now also save current generation count
    // Let's grab a lock first. We can do better here as we
    // only need to read the value of that variable
    GRAB_LOCK();
    br_gcount_ = gGenCount;
    RELEASE_LOCK();
}

////////////////////////////////////////////////////
//     Function about processing record
////////////////////////////////////////////////////

static void PerformUndoRecord(UndoRecord *record)
{
    if(record == NULL) return;
    // Undo records are applied in reverse order
    UndoRecord::reverse_iterator i = record->rbegin();
    for(; i != record->rend(); i++)
        (*i)->PerformUndo();
}

void AddEntryToMemAccessRecord(void* address, uint32_t size, void* contents)
{
    // If this is last branch point then that means we are executing the last
    // thread of control. And then we do not have to record at all because
    // we are never going to rollback.
    if(g_bpstack.empty())
        return;

    void* dupcontents = malloc(size);
    memcpy(dupcontents, contents, size);
    MemAccessRecordEntry* entry = new MemAccessRecordEntry (address, size, dupcontents);

#if 0
    DEBUG_PRINTF("Saving contents ");
    char* p = (char*) entry->GetContents();
    for(int i = 0; i < entry->GetSize(); i++)
        DEBUG_PRINTF("%2x:", *p++);
    DEBUG_PRINTF(" of [%p, %p+%d] to record", entry->GetAddress(), 
            entry->GetAddress(), entry->GetSize());
#endif

    BranchPoint* curr_active_branch_point = g_bpstack.top();
    curr_active_branch_point->br_urec_.push_back(entry);
}

void AddEntryToSymMetadataAccessRecord (SymMetaDataEntryType etype, void* address, 
        uint64_t gcount, void* sval)
{
    if(g_bpstack.empty())
        return;

    SymMetadataRecordEntry* entry = new SymMetadataRecordEntry (etype, address, 
            gcount, (struct sval_t*) sval);
    BranchPoint* curr_active_branch_point = g_bpstack.top();
    curr_active_branch_point->br_symmetarec_.push_back(entry);
}

#define MB (1024*1024)
char pgstack[1*MB];
void* pg_stack_top;
uint64_t pg_stack_size;

static void SaveStackToGlobalMem (BranchPoint* bp)
{
    if(bp == NULL)
        return;

    uintptr_t size = (char*) bp->br_ar_higher_ - (char*) bp->br_ar_lower_;
    memcpy(&pgstack[0], bp->br_arp_, size);
}

//////////////////////////////////////////////////
//    Functions about branch point
//////////////////////////////////////////////////

static void PrintBranchPointStack()
{
    INFO_PRINTF("Printing BP stack");
    if (g_bpstack.empty()) {
      INFO_PRINTF("BP stack empty");
      return;
    }
	
    BranchPoint* bp = g_bpstack.top();
		if (bp == NULL)
			return;

		uint32_t depth = 0;
		uint32_t size = 0;
		for(; bp->br_parent_ != NULL; bp = bp->br_parent_, ++depth) {
			size += bp->br_notes_.c_str() ? strlen(bp->br_notes_.c_str()) : 0;
			size += 10; // bid and "->"
		}
		
		if (depth == 0)
			return;

		char* buf = (char*) malloc ((depth*1024)+1);
		assert(buf != NULL);
		memset(buf, 0, (depth*1024)+1);
		strcpy(buf, "[BRSTACK] ");

    bp = g_bpstack.top();
    while(bp != NULL) {
			char tbuf[1024];
			memset(tbuf, 0, 1024);
			//snprintf(tbuf, 1024, "%llu->", bp->br_bid_), bp->br_notes_.c_str();
			tbuf[1023] = 0;
			strcat(buf, tbuf);
      bp = bp->br_parent_;
    } 
		INFO_PRINTF(buf);   
		free(buf);

}

bool isGVFileOpen = false;
FILE* gvfile = stderr;
const char* gvfile_path = "/tmp/x86";
#define START_LABEL "start"

int openGVFile(int loglevel)
{
		if (loglevel == DEBUG) {
			char buf[128];
			memset(buf, 0, 128);
			snprintf(buf, 128, "%s.%d.dot", gvfile_path, getpid());
			gvfile = fopen(buf, "w");
			if (gvfile == NULL)
				fatal("Error operning gv file");
			isGVFileOpen = true;
			fprintf(gvfile, "digraph {\n");
			fprintf(gvfile, "0 [label=\"start (\\N)\"];\n");
		}
		g_bpmap.insert(make_pair(START_LABEL, make_pair(0, 1)));
}

int SetupBranchPoint ()
{
		if (loglevel == DEBUG || loglevel == INFO) {
    	if (!isGVFileOpen) openGVFile(loglevel);
		}

		// Get current value of esp which tells us the stack top.
    void* stack_top;
    BranchPoint* bp;
		char* filenline;
    int ret;
    bp = new BranchPoint();
		bp->br_notes_ = gLoc ? gLoc : " ";
    bp->br_parent_ = g_bpstack.empty() ? NULL : g_bpstack.top();

		if (loglevel == DEBUG || loglevel == INFO) {
			/* Print node stmt in gv file when a new node is created. */
			/* BID [label="BR Loc" (\N)]; */
			uint64_t curr_brid = bp->br_bid_;
			uint64_t count;
			if (bp->br_notes_.c_str() != NULL) {
				BpMap_t::iterator it = g_bpmap.find(bp->br_notes_);
				if (it == g_bpmap.end()) {
					count = 1;
					g_bpmap.insert(make_pair(bp->br_notes_, make_pair(bp->br_bid_, count)));
				} else {
					curr_brid = get<0>(it->second);
					count = get<1>(it->second);
					get<1>(it->second) = count+1;
				}

				it = g_bpmap.find(bp->br_parent_ && bp->br_parent_->br_notes_.c_str() ? 
							bp->br_parent_->br_notes_.c_str() : START_LABEL);
				assert (it != g_bpmap.end());
				uint64_t par_brid = get<0>(it->second);

				EdgeMap_t::iterator eit = g_edgemap.find(par_brid);
				if (eit == g_edgemap.end()) {
					unordered_map<uint64_t, uint64_t> p;
					p.insert(make_pair(curr_brid, 1));
					g_edgemap.insert(make_pair(par_brid, p));
				}
				else {
					unordered_map<uint64_t, uint64_t>::iterator ieit = eit->second.find(curr_brid);
					if (ieit == eit->second.end()) {
						eit->second.insert(make_pair(curr_brid, 1));
					} else
						(ieit->second)++;
				}
			}
		}

    g_bpstack.push(bp);
		bpStackDepth = g_bpstack.size();
    INFO_PRINTF("Creating a branchpoint id = %llu %s",  bp->br_bid_, bp->br_notes_.c_str());
    asm("\t movl %%esp,%0" : "=r"(stack_top));
    assert (stack_top < stack_bottom);
    // Take a snapshot of current full stack
    bp->SnapshotStack(stack_top, stack_bottom);
    if (setjmp(bp->br_jmpbuf_) == 0) {
        return 0;
    } else {
        // Reconstruct stack from snapshot
        memcpy(pg_stack_top, pgstack, pg_stack_size);
        // Now also restore current generation count
        // Let's grab a lock first.
        GRAB_LOCK();
        gGenCount = bp->br_gcount_;
        RELEASE_LOCK();

        DEBUG_PRINTF("Longjmp received for branch id = %llu", bp->br_bid_);
        delete bp;
        return 3;
    }
}

//#define SETUP_BRANCH_POINT(fie, bp) (setjmp(*bp->br_jmpbuf_) == 0)

static void GotoBranchPoint (BranchPoint *bp)
{
    assert(bp != NULL);

    uintptr_t size = (char*) bp->br_ar_higher_ - (char*) bp->br_ar_lower_;
    DEBUG_PRINTF("Going to branch bid = %llu, setting stack [%p, %p] size = %u bytes", 
            bp->br_bid_, bp->br_ar_lower_, bp->br_ar_higher_, size);

    // Setup the stack activation records
    SaveStackToGlobalMem(bp);

    // Undo the symbolic metadata record
    if (!bp->br_symmetarec_.empty()) {
        PerformUndoRecord(&bp->br_symmetarec_);
    }

#if 0
    // Now apply the execution record of the current function
    if (!fie->fie_erec_.empty())
        ApplyRecord(&fie->fie_erec_);
    
    DEBUG("\nbp=%p, Performing longjmp using jmpbuf = %p", bp, &bp->br_jmpbuf_);
    // Now apply execution records of all 
    vector<BranchPoint*>::const_iterator i = fie->fie_vbp_.begin();
    for(; bp->br_bid_ > (*i)->br_bid_; ++i) {
        DEBUG("\nApplying exec record for bid = %llu", (*i)->br_bid_);
        ApplyRecord(&(*i)->br_erec_);
    }
#endif

    // Since we follow depth first order, current branch point must be the last
    // in the vector.
    //assert(++i == fie->fie_vbp_.end());
    //DEBUG("\nGoing to perform longjmp with jmp_buf = %p size=%d", &bp->br_jmpbuf_, sizeof(jmp_buf));

    //static jmp_buf tmp; 
    //memcpy(tmp, bp->br_jmpbuf_, sizeof(jmp_buf));
    // Let's perform longjump now
    
    //memcpy(bp->br_ar_lower_, bp->br_arp_, size);
    
    pg_stack_size = size;
    pg_stack_top = bp->br_ar_lower_;

    longjmp(bp->br_jmpbuf_, 1);
}

void GotoNextBranchPoint()
{
		DEBUG_PRINTF("In GotoNextBranchPoint");
    if(!g_bpstack.empty()) {
        //PrintBranchPointStack();
				bpStackDepth = g_bpstack.size();
        BranchPoint* nextbp = g_bpstack.top();
        g_bpstack.pop();
        INFO_PRINTF("Going to branch ID: %llu", nextbp->br_bid_);
        GotoBranchPoint(nextbp);
    } else {
        DEBUG_PRINTF("\nBranch Point stack is empty.");
				if (loglevel == DEBUG || loglevel == INFO) {
					BpMap_t::const_iterator cit = g_bpmap.cbegin();
					for(; cit != g_bpmap.cend(); cit++) {
						string loc = cit->first;
						uint64_t bid = get<0>(cit->second);
						uint64_t count = get<1>(cit->second);
						fprintf(gvfile, "%llu [label=\"%s (bid=\\N, c=%llu)\"];\n", bid,
							loc.c_str() ? loc.c_str() : "<NULL>", count);
					}

					EdgeMap_t::const_iterator ceit = g_edgemap.cbegin();
					for(; ceit != g_edgemap.cend(); ceit++) {
						unordered_map<uint64_t, uint64_t>::const_iterator ceeit = ceit->second.cbegin();
						for(; ceeit != ceit->second.cend(); ceeit++) {
							fprintf(gvfile, "%llu -> %llu [label=\"(cnt=%llu)\"];\n" , 
								ceit->first, ceeit->first, ceeit->second); 
						}
					}
					fprintf(gvfile, "}\n");
			}
#ifdef MEASURE
			print_measurements();
#endif
      exit(0);
    }
}



