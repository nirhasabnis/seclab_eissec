	.file	"alltype.c"
	.section	.rodata
.LC0:
	.string	"%d"
.LC1:
	.string	"i=%x ax=%x:%x ah=%x al=%x"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$52, %esp
	movl	$0, 40(%esp)
	movl	$.LC0, %eax
	leal	40(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__isoc99_scanf
	movl	40(%esp), %eax
	movb	%al, 47(%esp)
	movl	40(%esp), %eax
	andl	$65280, %eax
	sarl	$8, %eax
	movb	%al, 46(%esp)
	movl	40(%esp), %eax
	movb	%al, 38(%esp)
	movl	40(%esp), %eax
	andl	$65280, %eax
	sarl	$8, %eax
	movb	%al, 39(%esp)
	movsbl	47(%esp), %edi
	movsbl	46(%esp), %esi
	movzbl	38(%esp), %eax
	movsbl	%al, %ebx
	movzbl	39(%esp), %eax
	movsbl	%al, %ecx
	movl	40(%esp), %edx
	movl	$.LC1, %eax
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$0, %eax
	addl	$52, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.5.1"
	.section	.note.GNU-stack,"",@progbits
