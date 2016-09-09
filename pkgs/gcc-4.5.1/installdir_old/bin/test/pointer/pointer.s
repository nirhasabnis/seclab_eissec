	.file	"pointer.c"
	.section	.rodata
.LC0:
	.string	"%d"
	.text
.globl main
	.type	main, @function
main:
#(insn/f 27 3 28 pointer.c:6 (set (mem:SI (pre_dec:SI (reg/f:SI 7 sp)) [0 S4 A8])
#        (reg/f:SI 6 bp)) 38 {*pushsi2} (nil))
	pushl	%ebp	# 27	*pushsi2	[length = 1]
#(insn/f 28 27 29 pointer.c:6 (set (reg/f:SI 6 bp)
#        (reg/f:SI 7 sp)) 44 {*movsi_1} (nil))
	movl	%esp, %ebp	# 28	*movsi_1/1	[length = 2]
#(insn/f 29 28 30 pointer.c:6 (parallel [
#            (set (reg/f:SI 7 sp)
#                (and:SI (reg/f:SI 7 sp)
#                    (const_int -16 [0xfffffff0])))
#            (clobber (reg:CC 17 flags))
#        ]) 289 {*andsi_1} (nil))
	andl	$-16, %esp	# 29	*andsi_1/1	[length = 3]
#(insn/f 30 29 31 pointer.c:6 (parallel [
#            (set (reg/f:SI 7 sp)
#                (plus:SI (reg/f:SI 7 sp)
#                    (const_int -32 [0xffffffe0])))
#            (clobber (reg:CC 17 flags))
#            (clobber (mem:BLK (scratch) [0 A8]))
#        ]) 692 {pro_epilogue_adjust_stack_1} (nil))
	subl	$32, %esp	# 30	pro_epilogue_adjust_stack_1/1	[length = 3]
#(insn 5 2 26 pointer.c:7 (set (mem/c/i:SI (plus:SI (reg/f:SI 7 sp)
#                (const_int 24 [0x18])) [0 i+0 S4 A64])
#        (const_int 100 [0x64])) 44 {*movsi_1} (nil))
	movl	$100, 24(%esp)	# 5	*movsi_1/2	[length = 8]
#(insn 26 5 7 pointer.c:8 (set (reg:SI 0 ax [62])
#        (plus:SI (reg/f:SI 7 sp)
#            (const_int 24 [0x18]))) 196 {*lea_1} (nil))
	leal	24(%esp), %eax	# 26	*lea_1	[length = 4]
#(insn 7 26 8 pointer.c:8 (set (mem/f/c/i:SI (plus:SI (reg/f:SI 7 sp)
#                (const_int 28 [0x1c])) [0 p+0 S4 A32])
#        (reg:SI 0 ax [62])) 44 {*movsi_1} (expr_list:REG_EQUAL (plus:SI (reg/f:SI 7 sp)
#            (const_int 24 [0x18]))
#        (nil)))
	movl	%eax, 28(%esp)	# 7	*movsi_1/2	[length = 4]
#(insn 8 7 9 pointer.c:9 (set (reg/f:SI 0 ax [63])
#        (mem/f/c/i:SI (plus:SI (reg/f:SI 7 sp)
#                (const_int 28 [0x1c])) [0 p+0 S4 A32])) 44 {*movsi_1} (nil))
	movl	28(%esp), %eax	# 8	*movsi_1/1	[length = 4]
#(insn 9 8 10 pointer.c:9 (set (reg:SI 1 dx [orig:58 D.3782 ] [58])
#        (mem:SI (reg/f:SI 0 ax [63]) [0 S4 A32])) 44 {*movsi_1} (nil))
	movl	(%eax), %edx	# 9	*movsi_1/1	[length = 2]
#(insn 10 9 11 pointer.c:9 (set (reg/f:SI 0 ax [orig:59 D.3783 ] [59])
#        (symbol_ref/f:SI ("*.LC0") [flags 0x2]  <string_cst 0xb751df90>)) 44 {*movsi_1} (nil))
	movl	$.LC0, %eax	# 10	*movsi_1/1	[length = 5]
#(insn 11 10 12 pointer.c:9 (set (mem:SI (plus:SI (reg/f:SI 7 sp)
#                (const_int 4 [0x4])) [0 S4 A32])
#        (reg:SI 1 dx [orig:58 D.3782 ] [58])) 44 {*movsi_1} (nil))
	movl	%edx, 4(%esp)	# 11	*movsi_1/2	[length = 4]
#(insn 12 11 13 pointer.c:9 (set (mem:SI (reg/f:SI 7 sp) [0 S4 A32])
#        (reg/f:SI 0 ax [orig:59 D.3783 ] [59])) 44 {*movsi_1} (nil))
	movl	%eax, (%esp)	# 12	*movsi_1/2	[length = 3]
#(call_insn 13 12 14 pointer.c:9 (set (reg:SI 0 ax)
#        (call (mem:QI (symbol_ref:SI ("printf") [flags 0x41]  <function_decl 0xb7669f00 printf>) [0 S1 A8])
#            (const_int 8 [0x8]))) 697 {*call_value_0} (nil)
#    (nil))
	call	printf	# 13	*call_value_0	[length = 5]
#(insn 14 13 22 pointer.c:10 (set (reg:SI 0 ax [orig:60 D.3784 ] [60])
#        (const_int 0 [0x0])) 44 {*movsi_1} (nil))
	movl	$0, %eax	# 14	*movsi_1/1	[length = 5]
#(insn/f 33 32 34 pointer.c:11 (parallel [
#            (set (reg/f:SI 7 sp)
#                (plus:SI (reg/f:SI 6 bp)
#                    (const_int 4 [0x4])))
#            (set (reg/f:SI 6 bp)
#                (mem:SI (reg/f:SI 6 bp) [0 S4 A8]))
#            (clobber (mem:BLK (scratch) [0 A8]))
#        ]) 500 {leave} (expr_list:REG_CFA_RESTORE (reg/f:SI 6 bp)
#        (expr_list:REG_CFA_ADJUST_CFA (set (reg/f:SI 7 sp)
#                (plus:SI (reg/f:SI 6 bp)
#                    (const_int 4 [0x4])))
#            (nil))))
	leave	# 33	leave	[length = 1]
#(jump_insn 34 33 35 pointer.c:11 (return) 490 {return_internal} (nil))
	ret	# 34	return_internal	[length = 1]
	.size	main, .-main
	.ident	"GCC: (GNU) 4.5.1"
	.section	.note.GNU-stack,"",@progbits
