	.file	"float.c"
	.section	.rodata
.LC1:
	.string	"%d %f %c"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$48, %esp
	movl	$100, 44(%esp)
	movl	$0x400ccccd, %eax
	movl	%eax, 40(%esp)
	movb	$99, 39(%esp)
	movsbl	39(%esp), %edx
	flds	40(%esp)
	movl	$.LC1, %eax
	movl	%edx, 16(%esp)
	fstpl	8(%esp)
	movl	44(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$0, %eax
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.5.1"
	.section	.note.GNU-stack,"",@progbits
