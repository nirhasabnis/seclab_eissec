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
	imull	%edx, %eax
	movl	28(%esp), %edx
	movl	%edx, %ecx
	imull	%eax, %ecx
	movl	24(%esp), %edx
	movl	36(%esp), %eax
	leal	(%edx,%eax), %eax
	imull	%eax, %ecx

	movl	28(%esp), %eax
	movl	24(%esp), %edx
	imull	%edx, %eax
	leal	(%eax,%eax), %edx
	movl	36(%esp), %eax
	movl	%edx, %ebx
	imull	%eax, %ebx
	movl	44(%esp), %eax
	movl	%eax, %edx
	testl	%edx, %edx
	jne	.L2
	call	abort
.L2:
	movl	(%eax), %eax
	imull	%eax, %ebx
	
	movl	24(%esp), %edx
	movl	36(%esp), %eax
	leal	(%edx,%eax), %esi
	movl	44(%esp), %eax
	movl	%eax, %edx
	testl	%edx, %edx
	jne	.L3
	call	abort
.L3:
	movl	(%eax), %eax
	subl	%eax, %esi
	movl	%esi, %eax
	leal	(%ebx,%eax), %edx
	
	movl	32(%esp), %eax
	imull	%edx, %eax
	imull	%ecx, %eax
	
  movl	%eax, 40(%esp)
	movl	44(%esp), %eax
	movl	%eax, %edx
	testl	%edx, %edx
	jne	.L4
	call	abort
.L4:
	movl	(%eax), %edx
	movl	$.LC1, %eax
	movl	%edx, 8(%esp)
	movl	40(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	ret
	.size	main, .-main
