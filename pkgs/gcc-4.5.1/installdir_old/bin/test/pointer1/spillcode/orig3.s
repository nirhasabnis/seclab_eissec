	.file	"pointer3.c"
	.section	.rodata
.LC0:
	.string	"%d"
.LC1:
	.string	"\n res = %d, *t = %d\n"
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
	subl	$84, %esp
	movl	$.LC0, %eax
	leal	68(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__isoc99_scanf
	movl	$.LC0, %eax
	leal	64(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__isoc99_scanf
	movl	$.LC0, %eax
	leal	60(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__isoc99_scanf
	movl	$.LC0, %eax
	leal	56(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__isoc99_scanf
	movl	$.LC0, %eax
	leal	52(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__isoc99_scanf
	movl	$.LC0, %eax
	leal	48(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__isoc99_scanf
	movl	$.LC0, %eax
	leal	44(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__isoc99_scanf
	movl	$.LC0, %eax
	leal	40(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__isoc99_scanf
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
	
	leal	28(%esp), %eax
	movl	%eax, 76(%esp)

	movl	68(%esp), %edx
	movl	64(%esp), %eax
	leal	(%edx,%eax), %ecx
	
	movl	60(%esp), %edx
	movl	56(%esp), %eax
	leal	(%edx,%eax), %ebx
	
	movl	52(%esp), %edx
	movl	48(%esp), %eax
	leal	(%edx,%eax), %esi
	
	movl	44(%esp), %edx
	movl	40(%esp), %eax
	leal	(%edx,%eax), %edi
	
	movl	36(%esp), %edx
	movl	32(%esp), %eax
	addl	%eax, %edx
	
	movl	76(%esp), %eax
	movl	(%eax), %eax
	leal	(%edx,%eax), %eax
	leal	(%edi,%eax), %eax
	leal	(%esi,%eax), %eax
	leal	(%ebx,%eax), %eax
	leal	(%ecx,%eax), %eax
	movl	%eax, 72(%esp)
	
	movl	76(%esp), %eax
	movl	(%eax), %edx
	movl	$.LC1, %eax
	movl	%edx, 8(%esp)
	movl	72(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	
	movl	68(%esp), %edx
	movl	64(%esp), %eax
	movl	%edx, %ecx
	subl	%eax, %ecx
	movl	52(%esp), %edx
	movl	48(%esp), %eax
	movl	%edx, %ebx
	subl	%eax, %ebx
	movl	36(%esp), %edx
	movl	32(%esp), %eax
	subl	%eax, %edx
	movl	76(%esp), %eax
	movl	(%eax), %eax
	movl	%edx, %esi
	subl	%eax, %esi
	movl	40(%esp), %edx
	movl	44(%esp), %eax
	movl	%edx, %edi
	subl	%eax, %edi
	movl	%edi, %eax
	leal	(%esi,%eax), %eax
	addl	%eax, %ebx
	movl	56(%esp), %edx
	movl	60(%esp), %eax
	movl	%edx, %esi
	subl	%eax, %esi
	movl	%esi, %eax
	leal	(%ebx,%eax), %eax
	leal	(%ecx,%eax), %eax
	movl	%eax, 72(%esp)
	movl	76(%esp), %eax
	movl	(%eax), %edx
	movl	$.LC1, %eax
	movl	%edx, 8(%esp)
	movl	72(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$0, %eax
	addl	$84, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.5.1"
	.section	.note.GNU-stack,"",@progbits
