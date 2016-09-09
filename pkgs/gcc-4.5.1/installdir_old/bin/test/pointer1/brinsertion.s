	.file	"insertion.c"
	.section	.rodata
.LC0:
	.string	"Insertion sort."
.LC1:
	.string	"\nArray before sorting:"
.LC2:
	.string	"%d\t"
.LC3:
	.string	"\n\nArray after sorting:"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$48, %esp
	movl	$25, 28(%esp)
	movl	$17, 32(%esp)
	movl	$31, 36(%esp)
	movl	$13, 40(%esp)
	movl	$2, 44(%esp)
	.size	main, .-main
