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
	subl	$32, %esp
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
	movl	$.LC0, %eax
	movl	24(%esp), %edx
	movl	%edx, 8(%esp)
	movl	$6, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.5.1"
	.section	.note.GNU-stack,"",@progbits
