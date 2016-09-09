	.file	"spill.c"
	.section	.rodata
.LC0:
	.string	"\n %c %c %c"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	pushl	%esi
	pushl	%ebx
	subl	$1064, %esp
	movl	$0, 1052(%esp)
	jmp	.L2
.L9:
	movl	$0, 1048(%esp)
	jmp	.L3
.L8:
	movl	1048(%esp), %eax
	addl	$1, %eax
	movzbl	792(%esp,%eax), %ebx
	leal	792(%esp), %eax
	addl	1048(%esp), %eax
	movzbl	(%eax), %eax
	cmpb	%bl, %al
	jle	.L4
	movl	1048(%esp), %eax
	leal	1(%eax), %eax
	leal	792(%esp), %edx
	addl	1048(%esp), %edx
	movzbl	(%edx), %edx
	movb	%dl, 792(%esp,%eax)
	leal	792(%esp), %eax
	addl	1048(%esp), %eax
	movb	%bl, (%eax)
.L4:
	movl	1048(%esp), %eax
	addl	$1, %eax
	movzbl	536(%esp,%eax), %esi
	leal	536(%esp), %eax
	addl	1048(%esp), %eax
	movzbl	(%eax), %eax
	movl	%esi, %edx
	cmpb	%dl, %al
	jle	.L5
	movl	1048(%esp), %eax
	leal	1(%eax), %eax
	leal	536(%esp), %edx
	addl	1048(%esp), %edx
	movzbl	(%edx), %edx
	movb	%dl, 536(%esp,%eax)
	leal	536(%esp), %eax
	addl	1048(%esp), %eax
	movl	%esi, %edx
	movb	%dl, (%eax)
.L5:
	movl	%esi, %eax
	cmpb	%al, %bl
	jge	.L6
	leal	24(%esp), %edx
	addl	1048(%esp), %edx
	movb	%bl, (%edx)
	movl	1048(%esp), %edx
	leal	1(%edx), %ecx
	movl	%esi, %edx
	movb	%dl, 24(%esp,%ecx)
	jmp	.L7
.L6:
	leal	24(%esp), %edx
	movl	%edx, %ecx
	addl	1048(%esp), %ecx
	movl	%esi, %edx
	movb	%dl, (%ecx)
	movl	1048(%esp), %edx
	addl	$1, %edx
	movb	%bl, 24(%esp,%edx)
.L7:
	addl	$1, 1048(%esp)
.L3:
	cmpl	$255, 1048(%esp)
	jle	.L8
	addl	$1, 1052(%esp)
.L2:
	cmpl	$255, 1052(%esp)
	jle	.L9
	movl	$0, 1052(%esp)
	jmp	.L10
.L11:
	leal	24(%esp), %eax
	addl	1052(%esp), %eax
	movzbl	(%eax), %eax
	movsbl	%al, %ebx
	leal	536(%esp), %eax
	addl	1052(%esp), %eax
	movzbl	(%eax), %eax
	movsbl	%al, %ecx
	leal	792(%esp), %eax
	addl	1052(%esp), %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edx
	movl	$.LC0, %eax
	movl	%ebx, 12(%esp)
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	addl	$1, 1052(%esp)
.L10:
	cmpl	$255, 1052(%esp)
	jle	.L11
	ret
	.size	main, .-main
