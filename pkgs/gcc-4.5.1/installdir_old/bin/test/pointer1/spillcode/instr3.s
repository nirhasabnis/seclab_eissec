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
	subl	$100, %esp
	movl	$.LC0, %eax
	leal	84(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__isoc99_scanf
	movl	$.LC0, %eax
	leal	80(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__isoc99_scanf
	movl	$.LC0, %eax
	leal	76(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__isoc99_scanf
	movl	$.LC0, %eax
	leal	72(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__isoc99_scanf
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
	
	leal	44(%esp), %eax
	movl	%eax, 92(%esp)
	
	movl	84(%esp), %edx
	movl	80(%esp), %eax
	leal	(%edx,%eax), %ecx
	
	movl	76(%esp), %edx
	movl	72(%esp), %eax
	leal	(%edx,%eax), %ebx
	
	movl	68(%esp), %edx
	movl	64(%esp), %eax
	leal	(%edx,%eax), %esi
	
	movl	60(%esp), %edx
	movl	56(%esp), %eax
	leal	(%edx,%eax), %edi
	
	movl	52(%esp), %edx
	movl	48(%esp), %eax
	leal	(%edx,%eax), %eax
	movl	%eax, 28(%esp)     ; eax spilled to 28%(esp) which is not allocated
	                         ; to any local variable
	
	movl	92(%esp), %edx
	movl	%edx, %eax
	testl	%eax, %eax
	jne	.L2
	call	abort
.L2:
	movl	(%edx), %eax
	
	addl	28(%esp), %eax
	leal	(%edi,%eax), %eax
	leal	(%esi,%eax), %eax
	leal	(%ebx,%eax), %eax
	leal	(%ecx,%eax), %eax
	movl	%eax, 88(%esp)       
	
	movl	92(%esp), %eax
	movl	%eax, %edx
	testl	%edx, %edx
	jne	.L3
	call	abort
.L3:
	movl	(%eax), %edx
	movl	$.LC1, %eax
	movl	%edx, 8(%esp)
	movl	88(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf               ; call for first printf
	
	movl	84(%esp), %edx
	movl	80(%esp), %eax
	movl	%edx, %ecx
	subl	%eax, %ecx
	
	movl	68(%esp), %edx
	movl	64(%esp), %eax
	movl	%edx, %ebx
	subl	%eax, %ebx
	
	movl	52(%esp), %edx
	movl	48(%esp), %eax
	movl	%edx, %esi
	subl	%eax, %esi
	
	movl	92(%esp), %eax
	movl	%eax, %edx
	testl	%edx, %edx
	jne	.L4
	call	abort
.L4:
	movl	(%eax), %eax
	subl	%eax, %esi
	
	movl	56(%esp), %edx
	movl	60(%esp), %eax
	movl	%edx, %edi
	subl	%eax, %edi
	movl	%edi, %eax
	leal	(%esi,%eax), %eax
	addl	%eax, %ebx
	
	movl	72(%esp), %edx
	movl	76(%esp), %eax
	movl	%edx, %esi
	subl	%eax, %esi
	movl	%esi, %eax
	leal	(%ebx,%eax), %eax
	leal	(%ecx,%eax), %eax
	movl	%eax, 88(%esp)
	
	movl	92(%esp), %eax
	movl	%eax, %edx
	testl	%edx, %edx
	jne	.L5
	call	abort
.L5:
	movl	(%eax), %edx
	movl	$.LC1, %eax
	movl	%edx, 8(%esp)
	movl	88(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$0, %eax
	addl	$100, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.5.1"
	.section	.note.GNU-stack,"",@progbits
