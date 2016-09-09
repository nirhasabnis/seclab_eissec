	.file	"pointer2.c"
	.section	.rodata
.LC0:
	.string	"%d"
.LC1:
	.string	"\n res = %d, *s = %d\n"
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
	movl	$.LC0, %eax
	leal	24(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__isoc99_scanf
	movl	$.LC0, %eax
	leal	20(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__isoc99_scanf
	movl	$.LC0, %eax
	leal	16(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__isoc99_scanf
	movl	$.LC0, %eax
	movl	60(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__isoc99_scanf
	
	movl	52(%esp), %edx
	movl	48(%esp), %eax
	leal	(%edx,%eax), %ecx
	
	movl	44(%esp), %edx
	movl	40(%esp), %eax
	leal	(%edx,%eax), %ebx
	
	movl	36(%esp), %edx
	movl	32(%esp), %eax
	leal	(%edx,%eax), %esi
	
	movl	28(%esp), %edx
	movl	24(%esp), %eax
	leal	(%edx,%eax), %edi
	
	movl	20(%esp), %edx
	movl	16(%esp), %eax
	leal	(%edx,%eax), %eax
	movl	%eax, 28(%esp)

	movl	60(%esp), %edx
	movl	%edx, %eax
	testl	%eax, %eax
	jne	.L2
	call	abort
.L2:
	movl	(%edx), %eax
	
	movl	28(%esp), %edx
	leal	(%edx,%eax), %eax
	leal	(%edi,%eax), %eax
	leal	(%esi,%eax), %eax
	leal	(%ebx,%eax), %eax
	leal	(%ecx,%eax), %eax
	movl	%eax, 56(%esp)
	
	movl	60(%esp), %eax
	movl	%eax, %edx
	testl	%edx, %edx
	jne	.L3
	call	abort
.L3:
	movl	(%eax), %edx
	movl	$.LC1, %eax
	movl	%edx, 8(%esp)
	movl	56(%esp), %edx
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
