	.file	"matmult.c"
	.section	.rodata
	.align 4
.LC0:
	.string	"Enter The Rows And Cloumns And Of The First Matrix:"
.LC1:
	.string	"%d %d"
	.align 4
.LC2:
	.string	"\nEnter The Rows And Cloumns And Of The Second Matrix:"
	.align 4
.LC3:
	.string	"\nEnter Elements Of The First Matrix:"
.LC4:
	.string	"%d"
	.align 4
.LC5:
	.string	"\nEnter Elements Of The Second Matrix:"
.LC6:
	.string	"The First Matrix Is:"
.LC7:
	.string	" %d "
.LC8:
	.string	"The Second Matrix Is:"
	.align 4
.LC9:
	.string	"Aborting./nMultiplication Of The Above Matrices Not Possible."
	.align 4
.LC10:
	.string	"\nThe Product Of The Two Matrices Is:\n"
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
	subl	$1268, %esp
	movl	$.LC0, %eax
	movl	%eax, (%esp)
	call	printf
	movl	$.LC1, %eax
	leal	1244(%esp), %edx
	movl	%edx, 8(%esp)
	leal	1248(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__isoc99_scanf
	movl	$.LC2, %eax
	movl	%eax, (%esp)
	call	printf
	movl	$.LC1, %eax
	leal	1236(%esp), %edx
	movl	%edx, 8(%esp)
	leal	1240(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__isoc99_scanf
	movl	$.LC3, (%esp)
	call	puts
	movl	$0, 1260(%esp)
	jmp	.L2
.L5:
	movl	$0, 1256(%esp)
	jmp	.L3
.L4:
	leal	836(%esp), %ecx
	movl	1260(%esp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movl	%eax, %edx
	movl	1256(%esp), %eax
	leal	(%edx,%eax), %eax
	sall	$2, %eax
	leal	(%ecx,%eax), %edx
	movl	$.LC4, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__isoc99_scanf
	addl	$1, 1256(%esp)
.L3:
	movl	1244(%esp), %eax
	cmpl	%eax, 1256(%esp)
	jl	.L4
	addl	$1, 1260(%esp)
.L2:
	movl	1248(%esp), %eax
	cmpl	%eax, 1260(%esp)
	jl	.L5
	movl	$.LC5, (%esp)
	call	puts
	movl	$0, 1260(%esp)
	jmp	.L6
.L9:
	movl	$0, 1256(%esp)
	jmp	.L7
.L8:
	leal	436(%esp), %ecx
	movl	1260(%esp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movl	%eax, %edx
	movl	1256(%esp), %eax
	leal	(%edx,%eax), %eax
	sall	$2, %eax
	leal	(%ecx,%eax), %edx
	movl	$.LC4, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__isoc99_scanf
	addl	$1, 1256(%esp)
.L7:
	movl	1236(%esp), %eax
	cmpl	%eax, 1256(%esp)
	jl	.L8
	addl	$1, 1260(%esp)
.L6:
	movl	1240(%esp), %eax
	cmpl	%eax, 1260(%esp)
	jl	.L9
	movl	$.LC6, (%esp)
	call	puts
	movl	$0, 1260(%esp)
	jmp	.L10
.L13:
	movl	$0, 1256(%esp)
	jmp	.L11
.L12:
	movl	1260(%esp), %edx
	movl	1256(%esp), %ecx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	addl	%ecx, %eax
	movl	836(%esp,%eax,4), %edx
	movl	$.LC7, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	addl	$1, 1256(%esp)
.L11:
	movl	1244(%esp), %eax
	cmpl	%eax, 1256(%esp)
	jl	.L12
	movl	$10, (%esp)
	call	putchar
	addl	$1, 1260(%esp)
.L10:
	movl	1248(%esp), %eax
	cmpl	%eax, 1260(%esp)
	jl	.L13
	movl	$.LC8, (%esp)
	call	puts
	movl	$0, 1260(%esp)
	jmp	.L14
.L17:
	movl	$0, 1256(%esp)
	jmp	.L15
.L16:
	movl	1260(%esp), %edx
	movl	1256(%esp), %ecx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	addl	%ecx, %eax
	movl	436(%esp,%eax,4), %edx
	movl	$.LC7, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	addl	$1, 1256(%esp)
.L15:
	movl	1236(%esp), %eax
	cmpl	%eax, 1256(%esp)
	jl	.L16
	movl	$10, (%esp)
	call	putchar
	addl	$1, 1260(%esp)
.L14:
	movl	1240(%esp), %eax
	cmpl	%eax, 1260(%esp)
	jl	.L17
	movl	1244(%esp), %edx
	movl	1240(%esp), %eax
	cmpl	%eax, %edx
	je	.L18
	movl	$.LC9, %eax
	movl	%eax, (%esp)
	call	printf
	movl	$0, (%esp)
	call	exit
.L18:
	movl	$0, 1260(%esp)
	jmp	.L19
.L24:
	movl	$0, 1256(%esp)
	jmp	.L20
.L23:
	movl	1260(%esp), %edx
	movl	1256(%esp), %ecx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	addl	%ecx, %eax
	movl	$0, 36(%esp,%eax,4)
	movl	$0, 1252(%esp)
	jmp	.L21
.L22:
	movl	1260(%esp), %ebx
	movl	1256(%esp), %esi
	movl	1260(%esp), %edx
	movl	1256(%esp), %ecx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	addl	%ecx, %eax
	movl	36(%esp,%eax,4), %edi
	movl	1260(%esp), %edx
	movl	1252(%esp), %ecx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	addl	%ecx, %eax
	movl	836(%esp,%eax,4), %ecx
	movl	1252(%esp), %edx
	movl	1256(%esp), %eax
	movl	%eax, 28(%esp)
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	addl	28(%esp), %eax
	movl	436(%esp,%eax,4), %eax
	imull	%ecx, %eax
	leal	(%edi,%eax), %edx
	movl	%ebx, %eax
	sall	$2, %eax
	addl	%ebx, %eax
	addl	%eax, %eax
	addl	%esi, %eax
	movl	%edx, 36(%esp,%eax,4)
	addl	$1, 1252(%esp)
.L21:
	movl	1244(%esp), %eax
	cmpl	%eax, 1252(%esp)
	jl	.L22
	addl	$1, 1256(%esp)
.L20:
	movl	1236(%esp), %eax
	cmpl	%eax, 1256(%esp)
	jl	.L23
	addl	$1, 1260(%esp)
.L19:
	movl	1248(%esp), %eax
	cmpl	%eax, 1260(%esp)
	jl	.L24
	movl	$.LC10, (%esp)
	call	puts
	movl	$0, 1260(%esp)
	jmp	.L25
.L28:
	movl	$0, 1256(%esp)
	jmp	.L26
.L27:
	movl	1260(%esp), %edx
	movl	1256(%esp), %ecx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	addl	%ecx, %eax
	movl	36(%esp,%eax,4), %edx
	movl	$.LC7, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	addl	$1, 1256(%esp)
.L26:
	movl	1236(%esp), %eax
	cmpl	%eax, 1256(%esp)
	jl	.L27
	movl	$10, (%esp)
	call	putchar
	addl	$1, 1260(%esp)
.L25:
	movl	1248(%esp), %eax
	cmpl	%eax, 1260(%esp)
	jl	.L28
	addl	$1268, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	movl	%ebp, %esp
	popl	%ebp
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.4.3-4ubuntu5) 4.4.3"
	.section	.note.GNU-stack,"",@progbits
