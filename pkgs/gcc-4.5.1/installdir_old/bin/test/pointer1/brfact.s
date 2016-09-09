	.file	"fact.c"
	.section	.rodata
.LC0:
	.string	"The factorial of %d is %d\n"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$16, %esp
	movl	$1, 24(%esp)
	movl	$1, 28(%esp)
	jmp	.L2
.L3:
	movl	24(%esp), %eax
	imull	28(%esp), %eax
	movl	%eax, 24(%esp)
	addl	$1, 28(%esp)
.L2:
	cmpl	$6, 28(%esp)
	jle	.L3
	movl	24(%esp), %eax
	movl	%eax, 8(%esp)
	movl	$6, 4(%esp)
	leave
	.size	main, .-main
