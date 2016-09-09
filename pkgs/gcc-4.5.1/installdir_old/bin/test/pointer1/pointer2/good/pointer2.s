	.file	"pointer2.c"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$32, %esp
	movl	$0, 28(%esp)
	movl	28(%esp), %eax
	movl	%eax, %edx
	testl	%edx, %edx
	jne	.L2
	call	abort
.L2:
	movzbl	(%eax), %eax
	movb	%al, 27(%esp)
	movsbl	27(%esp), %eax
	movl	%eax, (%esp)
	call	putchar
	movl	$0, %eax
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.5.1"
	.section	.note.GNU-stack,"",@progbits
