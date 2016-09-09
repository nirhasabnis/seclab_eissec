	.file	"modgenerateMTF.c"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$6355908, %esp
	movl	$0, -20(%ebp)
	jmp	.L2
.L31:
	movl	$0, -16(%ebp)
	jmp	.L3
.L4:
	movl	-16(%ebp), %ecx
	movl	$239024267, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$6, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	movl	%edx, %ebx
	subl	%eax, %ebx
	movl	%ebx, %eax
	imull	$1150, %eax, %eax
	movl	%ecx, %edx
	subl	%eax, %edx
	movl	%edx, %eax
	addl	$235354, %eax
	movl	%eax, %edx
	movl	-16(%ebp), %eax
	movl	%edx, -3655692(%ebp,%eax,4)
	movl	-16(%ebp), %eax
	leal	1150(%eax), %edx
	movl	%edx, %eax
	sarl	$31, %eax
	shrl	$24, %eax
	addl	%eax, %edx
	andl	$255, %edx
	movl	%edx, %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, %edx
	leal	-4555692(%ebp), %eax
	addl	-16(%ebp), %eax
	movb	%dl, (%eax)
	addl	$1, -16(%ebp)
.L3:
	cmpl	$899980, -16(%ebp)
	jle	.L4
	leal	-3655692(%ebp), %eax
	movl	%eax, -55740(%ebp)
	leal	-4555692(%ebp), %eax
	movl	%eax, -55736(%ebp)
	leal	-6355654(%ebp), %eax
	movl	%eax, -55732(%ebp)
	movl	$899975, -55712(%ebp)
	movl	$256, -55696(%ebp)
	movl	$0, -16(%ebp)
	jmp	.L5
.L6:
	leal	-55704(%ebp), %eax
	addl	-16(%ebp), %eax
	movb	$1, 12(%eax)
	movl	-16(%ebp), %eax
	movl	%eax, %edx
	leal	-55448(%ebp), %eax
	addl	-16(%ebp), %eax
	movb	%dl, 12(%eax)
	addl	$1, -16(%ebp)
.L5:
	cmpl	$255, -16(%ebp)
	jle	.L6
	movl	$0, -55164(%ebp)
	movl	$4, -55160(%ebp)
	leal	-55768(%ebp), %eax
	movl	%eax, -32(%ebp)
	movl	-32(%ebp), %eax
	movl	28(%eax), %eax
	movl	%eax, -36(%ebp)
	movl	-32(%ebp), %eax
	movl	32(%eax), %eax
	movl	%eax, -40(%ebp)
	movl	-32(%ebp), %eax
	movl	36(%eax), %eax
	movl	%eax, -44(%ebp)
	movl	-32(%ebp), %eax
	movl	$0, 72(%eax)
	movl	$0, -16(%ebp)
	jmp	.L7
.L9:
	movl	-32(%ebp), %eax
	addl	-16(%ebp), %eax
	addl	$64, %eax
	movzbl	12(%eax), %eax
	testb	%al, %al
	je	.L8
	movl	-32(%ebp), %eax
	movl	72(%eax), %eax
	movl	-32(%ebp), %edx
	addl	-16(%ebp), %edx
	addl	$320, %edx
	movb	%al, 12(%edx)
	movl	-32(%ebp), %eax
	movl	72(%eax), %eax
	leal	1(%eax), %edx
	movl	-32(%ebp), %eax
	movl	%edx, 72(%eax)
.L8:
	addl	$1, -16(%ebp)
.L7:
	cmpl	$255, -16(%ebp)
	jle	.L9
	movl	-32(%ebp), %eax
	movl	72(%eax), %eax
	addl	$1, %eax
	movl	%eax, -48(%ebp)
	movl	$0, -16(%ebp)
	jmp	.L10
.L11:
	movl	-32(%ebp), %eax
	movl	-16(%ebp), %edx
	addl	$152, %edx
	movl	$0, 12(%eax,%edx,4)
	addl	$1, -16(%ebp)
.L10:
	movl	-16(%ebp), %eax
	cmpl	-48(%ebp), %eax
	jle	.L11
	movl	$0, -28(%ebp)
	movl	$0, -24(%ebp)
	movl	$0, -16(%ebp)
	jmp	.L12
.L13:
	movl	-16(%ebp), %eax
	movl	%eax, %edx
	leal	-6355910(%ebp), %eax
	addl	-16(%ebp), %eax
	movb	%dl, (%eax)
	addl	$1, -16(%ebp)
.L12:
	movl	-32(%ebp), %eax
	movl	72(%eax), %eax
	cmpl	-16(%ebp), %eax
	jg	.L13
	movl	$0, -16(%ebp)
	jmp	.L14
.L25:
	movl	-16(%ebp), %eax
	sall	$2, %eax
	addl	-36(%ebp), %eax
	movl	(%eax), %eax
	subl	$1, %eax
	movl	%eax, -20(%ebp)
	cmpl	$0, -20(%ebp)
	jns	.L15
	movl	-32(%ebp), %eax
	movl	56(%eax), %eax
	addl	%eax, -20(%ebp)
.L15:
	movl	-20(%ebp), %eax
	addl	-40(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	movl	-32(%ebp), %edx
	movzbl	332(%edx,%eax), %eax
	movb	%al, -49(%ebp)
	movzbl	-6355910(%ebp), %eax
	cmpb	-49(%ebp), %al
	jne	.L16
	addl	$1, -24(%ebp)
	jmp	.L17
.L16:
	cmpl	$0, -24(%ebp)
	jle	.L18
	subl	$1, -24(%ebp)
.L22:
	movl	-24(%ebp), %eax
	andl	$1, %eax
	testb	%al, %al
	je	.L19
	movl	-28(%ebp), %eax
	addl	%eax, %eax
	addl	-44(%ebp), %eax
	movw	$1, (%eax)
	addl	$1, -28(%ebp)
	movl	-32(%ebp), %eax
	movl	624(%eax), %eax
	leal	1(%eax), %edx
	movl	-32(%ebp), %eax
	movl	%edx, 624(%eax)
	jmp	.L20
.L19:
	movl	-28(%ebp), %eax
	addl	%eax, %eax
	addl	-44(%ebp), %eax
	movw	$0, (%eax)
	addl	$1, -28(%ebp)
	movl	-32(%ebp), %eax
	movl	620(%eax), %eax
	leal	1(%eax), %edx
	movl	-32(%ebp), %eax
	movl	%edx, 620(%eax)
.L20:
	cmpl	$1, -24(%ebp)
	jg	.L21
	movl	$0, -24(%ebp)
	jmp	.L18
.L21:
	movl	-24(%ebp), %eax
	subl	$2, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	leal	(%edx,%eax), %eax
	sarl	%eax
	movl	%eax, -24(%ebp)
	jmp	.L22
.L18:
	movzbl	-6355909(%ebp), %esi
	movzbl	-6355910(%ebp), %eax
	movb	%al, -6355909(%ebp)
	leal	-6355910(%ebp), %eax
	leal	1(%eax), %ebx
	movzbl	-49(%ebp), %eax
	movb	%al, -6355917(%ebp)
	jmp	.L23
.L24:
	addl	$1, %ebx
	movl	%esi, %edi
	movzbl	(%ebx), %esi
	movl	%edi, %edx
	movb	%dl, (%ebx)
.L23:
	movl	%esi, %ecx
	cmpb	%cl, -6355917(%ebp)
	jne	.L24
	movl	%esi, %eax
	movb	%al, -6355910(%ebp)
	movl	%ebx, %edx
	leal	-6355910(%ebp), %eax
	movl	%edx, %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, -20(%ebp)
	movl	-28(%ebp), %eax
	addl	%eax, %eax
	addl	-44(%ebp), %eax
	movl	-20(%ebp), %edx
	addl	$1, %edx
	movw	%dx, (%eax)
	addl	$1, -28(%ebp)
	movl	-20(%ebp), %eax
	addl	$1, %eax
	movl	-32(%ebp), %edx
	leal	152(%eax), %ecx
	movl	12(%edx,%ecx,4), %edx
	leal	1(%edx), %ecx
	movl	-32(%ebp), %edx
	addl	$152, %eax
	movl	%ecx, 12(%edx,%eax,4)
.L17:
	addl	$1, -16(%ebp)
.L14:
	movl	-32(%ebp), %eax
	movl	56(%eax), %eax
	cmpl	-16(%ebp), %eax
	jg	.L25
	cmpl	$0, -24(%ebp)
	jle	.L26
	subl	$1, -24(%ebp)
.L30:
	movl	-24(%ebp), %eax
	andl	$1, %eax
	testb	%al, %al
	je	.L27
	movl	-28(%ebp), %eax
	addl	%eax, %eax
	addl	-44(%ebp), %eax
	movw	$1, (%eax)
	addl	$1, -28(%ebp)
	movl	-32(%ebp), %eax
	movl	624(%eax), %eax
	leal	1(%eax), %edx
	movl	-32(%ebp), %eax
	movl	%edx, 624(%eax)
	jmp	.L28
.L27:
	movl	-28(%ebp), %eax
	addl	%eax, %eax
	addl	-44(%ebp), %eax
	movw	$0, (%eax)
	addl	$1, -28(%ebp)
	movl	-32(%ebp), %eax
	movl	620(%eax), %eax
	leal	1(%eax), %edx
	movl	-32(%ebp), %eax
	movl	%edx, 620(%eax)
.L28:
	cmpl	$1, -24(%ebp)
	jg	.L29
	movl	$0, -24(%ebp)
	jmp	.L26
.L29:
	movl	-24(%ebp), %eax
	subl	$2, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	leal	(%edx,%eax), %eax
	sarl	%eax
	movl	%eax, -24(%ebp)
	jmp	.L30
.L26:
	movl	-28(%ebp), %eax
	addl	%eax, %eax
	addl	-44(%ebp), %eax
	movl	-48(%ebp), %edx
	movw	%dx, (%eax)
	addl	$1, -28(%ebp)
	movl	-32(%ebp), %eax
	movl	-48(%ebp), %edx
	addl	$152, %edx
	movl	12(%eax,%edx,4), %eax
	leal	1(%eax), %ecx
	movl	-32(%ebp), %eax
	movl	-48(%ebp), %edx
	addl	$152, %edx
	movl	%ecx, 12(%eax,%edx,4)
	movl	-32(%ebp), %eax
	movl	-28(%ebp), %edx
	movl	%edx, 616(%eax)
	addl	$1, -20(%ebp)
.L2:
	cmpl	$99, -20(%ebp)
	jle	.L31
	movl	$0, %eax
	addl	$6355908, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.5.1"
	.section	.note.GNU-stack,"",@progbits
