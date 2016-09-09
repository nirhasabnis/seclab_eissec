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

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

// In a loop, reads input, performs some computation that is
// linear in input size, and always writes back "1"

char buf[100000];
char *y = "1\n";
char *n = "f\n";
int k=5;
int main(int argc, char *argv[]) {
   unsigned nr;
   unsigned i, j;
   int reqs=0, ops=0;
   int rv=0;
   // fprintf(stderr, "%s launched\n", argv[0]);
   while ((nr = read(0, buf, sizeof(buf))) > 0) {
      buf[nr] = '\0';
      //fprintf(stderr, "%s: read %d bytes [%s]\n", argv[0], nr, buf);
      reqs++;
      for (i = 0; i < k; i++) {
         for (j = 0; j < nr; j++) {
            ops++;
            rv += buf[j];
            if (i < nr)
               rv += buf[i];
         }
      }
      write(1, y, 2);
   }
   //fprintf(stderr, "%s: Exiting after processing %d requests, %d operations\n",
   //      argv[0], reqs, ops);
   return rv;
}
