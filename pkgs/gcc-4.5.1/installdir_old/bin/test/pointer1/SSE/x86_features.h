/*
 * x86_features.h
 * x86 feature bits
 *
 * Copyright (c) 2008-2011 Jan Seiffert
 *
 * This file is part of g2cd.
 *
 * g2cd is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3
 * of the License, or (at your option) any later version.
 *
 * g2cd is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with g2cd.
 * If not, see <http://www.gnu.org/licenses/>.
 *
 * $Id:$
 */

#ifndef X86_FEATURE_H
# define X86_FEATURE_H

# define FEATURE1(x,y,z) ENUM_CMD(x,  y)
# define FEATURE2(x,y,z) ENUM_CMD(x, (y +  32))
# define FEATURE3(x,y,z) ENUM_CMD(x, (y +  64))
# define FEATURE4(x,y,z) ENUM_CMD(x, (y +  96))
# define FEATURE5(x,y,z) ENUM_CMD(x, (y + 128))
# define FEATURE6(x,y,z) ENUM_CMD(x, (y + 160))
# define FEATURE7(x,y,z) ENUM_CMD(x, (y + 192))
# define X86_CPU_FEATURE_ENUM \
	FEATURE1( FPU       ,  0, "FPU on chip"                       ), \
	FEATURE1( VME       ,  1, "Virtual-8086 Mode Extensions"      ), \
	FEATURE1( DE        ,  2, "Debugging Extensions"              ), \
	FEATURE1( PSE       ,  3, "Page Size Extensions"              ), \
	FEATURE1( TSC       ,  4, "Time Stamp Counter"                ), \
	FEATURE1( MSR       ,  5, "RDMSR avail."                      ), \
	FEATURE1( PAE       ,  6, "Phys. Address Extensions"          ), \
	FEATURE1( MCE       ,  7, "Machine Check Execptions"          ), \
	FEATURE1( CX8       ,  8, "CMPXCHG8 instruction"              ), \
	FEATURE1( APIC      ,  9, "APIC on chip"                      ), \
	FEATURE1( RES_1_10  , 10, "Reserved"                          ), \
	FEATURE1( SEP       , 11, "SYSENTER avail."                   ), \
	FEATURE1( MTRR      , 12, "Mem. Type Range Regs"              ), \
	FEATURE1( PGE       , 13, "PTE Global Bit"                    ), \
	FEATURE1( MCA       , 14, "Machine Check Arch."               ), \
	FEATURE1( CMOV      , 15, "CMOV avail."                       ), \
	FEATURE1( PAT       , 16, "Page Attribute Table"              ), \
	FEATURE1( PSE36     , 17, "Page Size Extention"               ), \
	FEATURE1( PSN       , 18, "Processor Serial Number"           ), \
	FEATURE1( CLFSH     , 19, "CLFLUSH avail."                    ), \
	FEATURE1( RES_1_20  , 20, "Reserved"                          ), \
	FEATURE1( DS        , 21, "Debug Store"                       ), \
	FEATURE1( ACPI      , 22, "Thermal Monitoring and Clock Ctrl" ), \
	FEATURE1( MMX       , 23, "MMX Technology"                    ), \
	FEATURE1( FXSR      , 24, "FXSAVE avail."                     ), \
	FEATURE1( SSE       , 25, "SSE Extensions"                    ), \
	FEATURE1( SSE2      , 26, "SSE2 Extensions"                   ), \
	FEATURE1( SS        , 27, "Self Snoop Support"                ), \
	FEATURE1( HTT       , 28, "SMT Multi-threading"               ), \
	FEATURE1( TM        , 29, "Thermal Monitor"                   ), \
	FEATURE1( IA64      , 30, "IA-64, Itanium in x86 mode"        ), \
	FEATURE1( PBE       , 31, "Pending Break Enable"              ), \
	FEATURE2( SSE3      ,  0, "SSE3 Extensions"                   ), \
	FEATURE2( PCLMULQDQ ,  1, "PCLMULQDQ avail."                  ), \
	FEATURE2( DTES64    ,  2, "64-Bit Debug Store"                ), \
	FEATURE2( MONITOR   ,  3, "MONITOR avail."                    ), \
	FEATURE2( DSCPL     ,  4, "CPL Qualified Debug Store"         ), \
	FEATURE2( VMX       ,  5, "Virtual Machine Extensions"        ), \
	FEATURE2( SMX       ,  6, "Safer Mode Extensions"             ), \
	FEATURE2( EST       ,  7, "Enhanced Speed Step Technology"    ), \
	FEATURE2( TM2       ,  8, "Thermal Monitor 2"                 ), \
	FEATURE2( SSSE3     ,  9, "Supplemental SSE3 Extentions"      ), \
	FEATURE2( CNXTID    , 10, "L1 Cache Context switch avail."    ), \
	FEATURE2( RES_2_11  , 11, "Reserved"                          ), \
	FEATURE2( FMA       , 12, "Fused Multiply Add Extension"      ), \
	FEATURE2( CX16      , 13, "CMPXCHG16 avail."                  ), \
	FEATURE2( XTPR      , 14, "xTPR Update Control"               ), \
	FEATURE2( PDCM      , 15, "Performance and Debug Capabillity" ), \
	FEATURE2( RES_2_16  , 16, "Reserved"                          ), \
	FEATURE2( PCID      , 17, "Process-context identifiers"       ), \
	FEATURE2( DCA       , 18, "Direct Cache Access"               ), \
	FEATURE2( SSE4_1    , 19, "SSE4.1 Extensions"                 ), \
	FEATURE2( SSE4_2    , 20, "SSE4.2 Extensions"                 ), \
	FEATURE2( X2APIC    , 21, "x2APIC avail."                     ), \
	FEATURE2( MOVBE     , 22, "MOVBE avail."                      ), \
	FEATURE2( POPCNT    , 23, "POPCNT avail."                     ), \
	FEATURE2( TSC_DEAD  , 24, "TSC Deadline support"              ), \
	FEATURE2( AES       , 25, "AES Support"                       ), \
	FEATURE2( XSAVE     , 26, "XSAVE avail."                      ), \
	FEATURE2( OSXSAVE   , 27, "OS supports XSAVE"                 ), \
	FEATURE2( AVX       , 28, "AVX Extensions"                    ), \
	FEATURE2( F16C      , 29, "Float16 Conversions"               ), \
	FEATURE2( RDRAND    , 30, "Read Random"                       ), \
	FEATURE2( RAZ       , 31, "On a Hypervisor??"                 ), \
	FEATURE3( MIR_FPU   ,  0, "FPU on Chip, mirrored"             ), \
	FEATURE3( MIR_VME   ,  1, "Virtual Mode Extensions, mirrored" ), \
	FEATURE3( MIR_DE    ,  2, "Debugging Extensions, mirrored"    ), \
	FEATURE3( MIR_PSE   ,  3, "Page Size Extensions, mirrored"    ), \
	FEATURE3( MIR_TSC   ,  4, "Time Stamp Counter, mirrored"      ), \
	FEATURE3( MIR_MSR   ,  5, "RDMSR avail., mirrored"            ), \
	FEATURE3( MIR_PAE   ,  6, "Phys. Address Extensions, mirrored"), \
	FEATURE3( MIR_MCE   ,  7, "Machine Check Execptions, mirrored"), \
	FEATURE3( MIR_CX8   ,  8, "CMPXCHG8 instruction, mirrored"    ), \
	FEATURE3( MIR_APIC  ,  9, "APIC on chip, mirrored"            ), \
	FEATURE3( RES_3_10  , 10, "Reserved"                          ), \
	FEATURE3( SYSCALL   , 11, "SYSCALL avail."                    ), \
	FEATURE3( MIR_MTRR  , 12, "Mem. Type Range Regs, mirrored"    ), \
	FEATURE3( MIR_PGE   , 13, "PTE Global Bit, mirrored"          ), \
	FEATURE3( MIR_MCA   , 14, "Machine Check Arch., mirrored"     ), \
	FEATURE3( MIR_CMOV  , 15, "CMOV avail., mirrored"             ), \
	FEATURE3( MIR_PAT   , 16, "Page Attribute Table, mirrored"    ), \
	FEATURE3( MIR_PSE36 , 17, "Page Size Extention, mirrored"     ), \
	FEATURE3( RES_3_18  , 18, "Reserved"                          ), \
	FEATURE3( MP        , 19, "MP Capable"                        ), \
	FEATURE3( NX        , 20, "Execute Disable"                   ), \
	FEATURE3( RES_3_21  , 21, "Reserved"                          ), \
	FEATURE3( MMXEXT    , 22, "MMX Technology Extensions"         ), \
	FEATURE3( MIR_MMX   , 23, "MMX Technology, mirrored"          ), \
	FEATURE3( MIR_FXSR  , 24, "FXSAVE avail., mirrored"           ), \
	FEATURE3( FFXSR     , 25, "FXSAVE optimizations"              ), \
	FEATURE3( PAGE1GB   , 26, "1 Giga byte pages supported"       ), \
	FEATURE3( RDTSCP    , 27, "RDTSCP avail."                     ), \
	FEATURE3( RES_3_28  , 28, "Reserved"                          ), \
	FEATURE3( LM        , 29, "Longmode, 64Bit avail."            ), \
	FEATURE3( 3DNOWEXT  , 30, "3DNow! Extended supported"         ), \
	FEATURE3( 3DNOW     , 31, "3DNow! supported"                  ), \
	FEATURE4( LAHF      ,  0, "LAHF avail. (in 64Bit)"            ), \
	FEATURE4( CMPLEGA   ,  1, "If yes HyperThreading not valid"   ), \
	FEATURE4( SVM       ,  2, "Secure Virtual Machine"            ), \
	FEATURE4( EAPIC     ,  3, "Extended APIC space"               ), \
	FEATURE4( AMOVCR    ,  4, "CR8 in 32Bit mode"                 ), \
	FEATURE4( ABM       ,  5, "Advanced bit manipulation"/*lzcnt*/), \
	FEATURE4( SSE4A     ,  6, "SSE4a Extensions"                  ), \
	FEATURE4( MASSE     ,  7, "Misaligned SSE mode"               ), \
	FEATURE4( 3DNOWPRE  ,  8, "3DNow! Prefetch instructions"      ), \
	FEATURE4( OSVW      ,  9, "OS Visible Workaround"             ), \
	FEATURE4( IBS       , 10, "Instruction Based Sampling"        ), \
	FEATURE4( XOP       , 11, "XOP Extensions"                    ), \
	FEATURE4( SKINIT    , 12, "SKINIT avail."                     ), \
	FEATURE4( WDT       , 13, "Watchdog timer"                    ), \
	FEATURE4( RES_4_14  , 14, "Reserved"                          ), \
	FEATURE4( LWP       , 15, "Lightweight Profiling"             ), \
	FEATURE4( FMA4      , 16, "FMA AMD-Style"                     ), \
	FEATURE4( RES_4_17  , 17, "Reserved"                          ), \
	FEATURE4( CVT16     , 18, "Half Float extention (obsolete?)"  ), \
	FEATURE4( NODEID_MSR, 19, "NodeID MSR"                        ), \
	FEATURE4( TBM       , 21, "Trailing bit manipulation"         ), \
	FEATURE4( TOPOEXT   , 22, "Topology ext. CPUID leafs"         ), \
	FEATURE5( FGSBASE   ,  0, "User Baseregister manipulation"    ), \
	FEATURE5( BMI       ,  3, "Bit manipulation inst." /*tzcnt*/  ), \
	FEATURE5( AVX2      ,  5, "AVX2"                              ), \
	FEATURE5( SMEP      ,  7, "Supervisor Mode NX"                ), \
	FEATURE5( BMI2      ,  8, "BMI2"                              ), \
	FEATURE5( ERMS      ,  9, "Enhanced REP MOVSB/STOSB"          ), \
	FEATURE5( INVPCID   , 10, "Invalidate Process-context ID"     ), \
	FEATURE6( PL_RNG    ,  2, "Padlock Random Number Generator"   ), \
	FEATURE6( PL_RNG_E  ,  3, "Padlock RNG enabled"               ), \
	FEATURE6( PL_ACE    ,  6, "Padlock Advanced Coding ..."       ), \
	FEATURE6( PL_ACE_E  ,  7, "Padlock ACE enabled"               ), \
	FEATURE6( PL_ACE2   ,  8, "Padlock ACE2 avail."               ), \
	FEATURE6( PL_ACE2_E ,  9, "Padlock ACE2 enabled"              ), \
	FEATURE6( PL_PHE    , 10, "Padlock Hashing Engine"            ), \
	FEATURE6( PL_PHE_E  , 11, "Padlock HE enabled"                ), \
	FEATURE6( PL_PMM    , 12, "Padlock Montgommery Multiplier"    ), \
	FEATURE6( PL_PMM_E  , 13, "Padlock MM enabled"                ), \
	FEATURE6( CX_MMX    , 31, "Cyrix MMX Ext." /* F3(MIR_FXSR) */ ), \
	FEATURE7( AP_FP128  ,  0, "SSE is 128 bit wide"               ), \
	FEATURE7( AP_MOVU   ,  1, "Movu instr. better then movl/movh" )

# define ENUM_CMD(x,y) CFEATURE_##x = y
enum x86_cpu_features
{
	X86_CPU_FEATURE_ENUM
};
# undef ENUM_CMD

extern const char x86_cpu_feature_names[][16] GCC_ATTR_VIS("hidden");

# ifdef __ELF__
#  define _DYN_JMP_SECTION_NAME ".plt"
#  ifdef __arm__
#   define _DYN_JMP_DBG_START(name) ".type	" #name ", #function\n"
#  else
#   define _DYN_JMP_DBG_START(name) ".type	" #name ", @function\n"
#  endif
#  define _DYN_JMP_DBG_END(name) ".size	" #name ", . - " #name "\n\t"
# else
#  define _DYN_JMP_SECTION_NAME ".text.jmp"
#  define _DYN_JMP_DBG_START(name) "\n"
#  define _DYN_JMP_DBG_END(name) "\n\t"
# endif

# ifdef USE_SIMPLE_DISPATCH
#  define _DYN_JMP_CONSTRUCTOR(name) \
	static GCC_ATTR_CONSTRUCT __init void name##_select(void) { \
		name##_ptr = test_cpu_feature(tfeat_##name, anum(tfeat_##name)); \
	}
# else
#  ifndef __PIC__
#   define _DYN_JMP_CONSTRUCTOR(name) \
	static GCC_ATTR_CONSTRUCT __init void name##_select(void) { \
		patch_instruction(name, tfeat_##name, anum(tfeat_##name)); \
	}
#  else
#   define _DYN_JMP_CONSTRUCTOR(name)
#  endif
# endif

# ifdef USE_SIMPLE_DISPATCH
#   define _DYN_JMP_RT_SWITCH(rtype, name, prot, call) \
	static __init rtype name##_runtime_sw prot { \
		name##_select(); \
		return name call; \
	}
#   define _DYN_JMP_RT_SWITCH_NR(name, prot, call) \
	static __init void name##_runtime_sw prot { \
		name##_select(); \
		name call; \
	}
# else
#  ifndef __PIC__
#   ifdef __x86_64__
#    define _DYN_JMP_RT_SWITCH(rtype, name, prot, call) \
	asm ( \
		".pushsection .text.unlikely\n\t" \
		_DYN_JMP_DBG_START(name##_runtime_sw) \
		#name "_runtime_sw:\n\t" \
		"push	%rdi\n\t" \
		"push	%rsi\n\t" \
		"push	%rdx\n\t" \
		"push	%rcx\n\t" \
		"push	%r8\n\t" \
		"push	%r9\n\t" \
		"call	" #name "_select\n\t" \
		"pop	%r9\n\t" \
		"pop	%r8\n\t" \
		"pop	%rcx\n\t" \
		"pop	%rdx\n\t" \
		"pop	%rsi\n\t" \
		"pop	%rdi\n\t" \
		"jmp	" #name "\n\t"\
		_DYN_JMP_DBG_END(name##_runtime_sw) \
		".popsection" \
	);
#   else
#    define _DYN_JMP_RT_SWITCH(rtype, name, prot, call) \
	asm ( \
		".pushsection .text.unlikely\n\t" \
		_DYN_JMP_DBG_START(name##_runtime_sw) \
		#name "_runtime_sw:\n\t" \
		"pushal\n\t" \
		"call	" #name "_select\n\t" \
		"popal\n\t" \
		"jmp	" #name "\n\t"\
		_DYN_JMP_DBG_END(name##_runtime_sw) \
		".popsection" \
	);
#   endif
#  else
#    define _DYN_JMP_RT_SWITCH(rtype, name, prot, call) \
static GCC_ATTR_USED void * name##_ifunc (void) { \
	return test_cpu_feature(tfeat_##name, anum(tfeat_##name)); \
}
#  endif
#  define _DYN_JMP_RT_SWITCH_NR(name, prot, call) _DYN_JMP_RT_SWITCH(void, name, prot, call)
# endif

# ifdef USE_SIMPLE_DISPATCH
#  define _DYN_JMP_REST_GEN(mod, rtype, name, prot, call, ret) \
	static rtype name##_runtime_sw prot; \
	static rtype (* name##_ptr) prot = name##_runtime_sw; \
	mod rtype name prot { \
		ret name##_ptr call; \
	}
#  define _DYN_JMP_REST(rtype, name, prot, call) _DYN_JMP_REST_GEN( , rtype, name, prot, call, return)
#  define _DYN_JMP_REST_NR(name, prot, call) _DYN_JMP_REST_GEN( , void, name, prot, call, )
#  define _DYN_JMP_REST_ALIAS(rtype, name, prot, call, sname) _DYN_JMP_REST(rtype, name, prot, call)
#  define _DYN_JMP_REST_ST(rtype, name, prot, call) _DYN_JMP_REST_GEN(static, rtype, name, prot, call, return)
# else
#  ifndef __PIC__
#   define _DYN_JMP_INSTRUCTION(name) \
	".byte	0xE9\n\t" /* make sure we get a jmp with displacement */ \
	".long	" #name "_runtime_sw - 1f\n\t" \
	".byte	0x00, 0x00\n" \
	"1:\n\t" \
	_DYN_JMP_DBG_END(name)
#   define _DYN_JMP_REST_GEN(name, name_export, alias, alias_export) \
	asm ( \
		".pushsection "_DYN_JMP_SECTION_NAME"\n\t" \
		name_export \
		_DYN_JMP_DBG_START(name) \
		#name ":\n\t" \
		_DYN_JMP_INSTRUCTION(name) \
		alias_export \
		alias \
		".popsection" \
	);
#  else
#   define _DYN_JMP_REST_GEN(name, name_export, alias, alias_export) \
	asm ( \
		".pushsection .text\n\t" \
		name_export \
		".type " #name ", @gnu_indirect_function\n" \
		".set	" #name "," #name "_ifunc\n\t" \
		alias_export \
		alias \
		".popsection" \
	);
#  endif
#  define _DYN_JMP_REST(rtype, name, prot, call) _DYN_JMP_REST_GEN(name, ".globl " #name "\n\t", , )
#  define _DYN_JMP_REST_NR(name, prot, call) _DYN_JMP_REST(void, name, prot, call)
#  define _DYN_JMP_REST_ALIAS(rtype, name, prot, call, sname) _DYN_JMP_REST_GEN(name, ".globl " #name "\n\t", ".set " #sname ", " #name "\n\t", ".globl " #sname "\n\t")
#  define _DYN_JMP_REST_ST(rtype, name, prot, call) _DYN_JMP_REST_GEN(name, ".local " #name "\n\t", , )
# endif

# define DYN_JMP_DISPATCH(rtype, name, prot, call) \
	_DYN_JMP_REST(rtype, name, prot, call) \
	_DYN_JMP_CONSTRUCTOR(name) \
	_DYN_JMP_RT_SWITCH(rtype, name, prot, call)

# define DYN_JMP_DISPATCH_NR(name, prot, call) \
	_DYN_JMP_REST_NR(name, prot, call) \
	_DYN_JMP_CONSTRUCTOR(name) \
	_DYN_JMP_RT_SWITCH_NR(name, prot, call)

# define DYN_JMP_DISPATCH_ALIAS(rtype, name, prot, call, sname) \
	_DYN_JMP_REST_ALIAS(rtype, name, prot, call, sname) \
	_DYN_JMP_CONSTRUCTOR(name) \
	_DYN_JMP_RT_SWITCH(rtype, name, prot, call)

# define DYN_JMP_DISPATCH_ST(rtype, name, prot, call) \
	_DYN_JMP_REST_ST(rtype, name, prot, call) \
	_DYN_JMP_CONSTRUCTOR(name) \
	_DYN_JMP_RT_SWITCH(rtype, name, prot, call)

#endif
