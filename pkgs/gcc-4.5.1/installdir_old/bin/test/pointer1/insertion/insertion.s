	.file	"insertion.c"
	.section	.rodata
.LC0:
	.string	"Insertion sort."
.LC1:
	.string	"\nArray before sorting:"
.LC2:
	.string	"%d\t"
.LC3:
	.string	"\n\nArray after sorting:"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$64, %esp
	movl	$25, 28(%esp)
	movl	$17, 32(%esp)
	movl	$31, 36(%esp)
	movl	$13, 40(%esp)
	movl	$2, 44(%esp)
	movl	$.LC0, (%esp)
	call	puts
	movl	$.LC1, (%esp)
	call	puts
	movl	$0, 60(%esp)
	jmp	.L2
.L3:
	movl	60(%esp), %eax
	movl	28(%esp,%eax,4), %edx
	movl	$.LC2, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	addl	$1, 60(%esp)
.L2:
	cmpl	$4, 60(%esp)
	jle	.L3
	movl	$1, 60(%esp)
	jmp	.L4
.L10:
	movl	$0, 56(%esp)
	jmp	.L5
.L9:
	movl	56(%esp), %eax
	movl	28(%esp,%eax,4), %edx
	movl	60(%esp), %eax
	movl	28(%esp,%eax,4), %eax
	cmpl	%eax, %edx
	jle	.L6
	movl	56(%esp), %eax
	movl	28(%esp,%eax,4), %eax
	movl	%eax, 48(%esp)
	movl	60(%esp), %eax
	movl	28(%esp,%eax,4), %edx
	movl	56(%esp), %eax
	movl	%edx, 28(%esp,%eax,4)
	movl	60(%esp), %eax
	movl	%eax, 52(%esp)
	jmp	.L7
.L8:
	movl	52(%esp), %eax
	subl	$1, %eax
	movl	28(%esp,%eax,4), %edx
	movl	52(%esp), %eax
	movl	%edx, 28(%esp,%eax,4)
	subl	$1, 52(%esp)
.L7:
	movl	52(%esp), %eax
	cmpl	56(%esp), %eax
	jg	.L8
	movl	52(%esp), %eax
	leal	1(%eax), %edx
	movl	48(%esp), %eax
	movl	%eax, 28(%esp,%edx,4)
.L6:
	addl	$1, 56(%esp)
.L5:
	movl	56(%esp), %eax
	cmpl	60(%esp), %eax
	jl	.L9
	addl	$1, 60(%esp)
.L4:
	cmpl	$4, 60(%esp)
	jle	.L10
	movl	$.LC3, (%esp)
	call	puts
	movl	$0, 60(%esp)
	jmp	.L11
.L12:
	movl	60(%esp), %eax
	movl	28(%esp,%eax,4), %edx
	movl	$.LC2, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	addl	$1, 60(%esp)
.L11:
	cmpl	$4, 60(%esp)
	jle	.L12
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.5.1"
	.section	.note.GNU-stack,"",@progbits
