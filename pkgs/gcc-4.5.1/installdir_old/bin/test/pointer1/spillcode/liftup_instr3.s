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
	leal	(%edx,%eax), %eax
  movl	%eax, 28(%esp)     ; eax spilled to memory which is allocated to local
                           ; variable

	movl	76(%esp), %edx
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
	movl	%eax, 72(%esp)
	
	movl	76(%esp), %eax
	movl	%eax, %edx
	testl	%edx, %edx
	jne	.L3
	call	abort
.L3:
	movl	(%eax), %edx
	movl	$.LC1, %eax
	movl	%edx, 8(%esp)
	movl	72(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf        ; call to first printf
	
	
  movl	68(%esp), %eax
	movl	64(%esp), %edx
	subl	%edx, %eax
	
	movl	52(%esp), %ecx
	movl	48(%esp), %edx
	subl	%edx, %ecx
	
	movl	36(%esp), %ebx
	movl	32(%esp), %edx
	movl	%ebx, %esi
	subl	%edx, %esi
	
	movl	76(%esp), %edx
	movl	%edx, %ebx
	testl	%ebx, %ebx
	jne	.L4
	call	abort
.L4:
	movl	(%edx), %ebx
	movl	%esi, %edx
	subl	%ebx, %edx
	movl	40(%esp), %ebx
	movl	44(%esp), %esi
	movl	%ebx, %edi
	subl	%esi, %edi
	movl	%edi, %ebx
	leal	(%edx,%ebx), %edx
	addl	%edx, %ecx
	movl	56(%esp), %edx
	movl	60(%esp), %ebx
	movl	%edx, %esi
	subl	%ebx, %esi
	movl	%esi, %edx
	leal	(%ecx,%edx), %edx
	leal	(%eax,%edx), %eax
	movl	%eax, 72(%esp)
	movl	76(%esp), %eax
	movl	%eax, %edx
	testl	%edx, %edx
	jne	.L5
	call	abort
.L5:
	movl	(%eax), %edx
	movl	$.LC1, %eax
	movl	%edx, 8(%esp)
	movl	72(%esp), %edx
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
