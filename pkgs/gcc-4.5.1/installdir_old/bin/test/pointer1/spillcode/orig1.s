	.file	"pointerd.c"
	.section	.rodata
.LC0:
	.string	"%d"
.LC1:
	.string	"\n m = %d, *n = %d\n"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	pushl	%esi
	pushl	%ebx
	subl	$56, %esp
	movl	$.LC0, %eax
	leal	36(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__isoc99_scanf
	movl	$.LC0, %eax
	leal	32(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__isoc99_scanf
	movl	$.LC0, %eax
	leal	28(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__isoc99_scanf
	movl	$.LC0, %eax
	leal	24(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__isoc99_scanf
	
	leal	28(%esp), %eax
	movl	%eax, 44(%esp)
	movl	36(%esp), %edx
	movl	32(%esp), %eax
	imull	%eax, %edx
	movl	28(%esp), %eax
	imull	%edx, %eax
	movl	24(%esp), %ecx
	movl	36(%esp), %edx
	leal	(%ecx,%edx), %edx
	imull	%eax, %edx
	
	movl	28(%esp), %ecx
	movl	24(%esp), %eax
	imull	%ecx, %eax
	leal	(%eax,%eax), %ecx
	movl	36(%esp), %eax
	imull	%eax, %ecx
	movl	44(%esp), %eax
	movl	(%eax), %eax
	imull	%eax, %ecx
	
	movl	24(%esp), %ebx
	movl	36(%esp), %eax
	addl	%eax, %ebx
	movl	44(%esp), %eax
	movl	(%eax), %eax
	movl	%ebx, %esi
	subl	%eax, %esi
	movl	%esi, %eax
	addl	%eax, %ecx
	
	movl	32(%esp), %eax
	imull	%ecx, %eax
	imull	%edx, %eax
	
  movl	%eax, 40(%esp)
	movl	44(%esp), %eax
	movl	(%eax), %edx
	movl	$.LC1, %eax
	movl	%edx, 8(%esp)
	movl	40(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$0, %eax
	addl	$56, %esp
	popl	%ebx
	popl	%esi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.5.1"
	.section	.note.GNU-stack,"",@progbits
