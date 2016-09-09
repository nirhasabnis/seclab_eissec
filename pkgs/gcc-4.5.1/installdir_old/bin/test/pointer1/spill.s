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
	movl	%eax, %edx
	testl	%edx, %edx
	jne	.L12
	call	abort
.L12:
	movzbl	(%eax), %eax
	cmpb	%bl, %al
	jle	.L4
	movl	1048(%esp), %eax
	leal	1(%eax), %edx
	leal	792(%esp), %eax
	addl	1048(%esp), %eax
	movl	%eax, %ecx
	testl	%ecx, %ecx
	jne	.L13
	call	abort
.L13:
	movzbl	(%eax), %eax
	movb	%al, 792(%esp,%edx)
	leal	792(%esp), %eax
	addl	1048(%esp), %eax
	movl	%eax, %edx
	testl	%edx, %edx
	jne	.L14
	call	abort
.L14:
	movb	%bl, (%eax)
.L4:
	movl	1048(%esp), %eax
	addl	$1, %eax
	movzbl	536(%esp,%eax), %esi
	leal	536(%esp), %eax
	addl	1048(%esp), %eax
	movl	%eax, %edx
	testl	%edx, %edx
	jne	.L15
	call	abort
.L15:
	movzbl	(%eax), %eax
	movl	%esi, %edx
	cmpb	%dl, %al
	jle	.L5
	movl	1048(%esp), %eax
	leal	1(%eax), %edx
	leal	536(%esp), %eax
	addl	1048(%esp), %eax
	movl	%eax, %ecx
	testl	%ecx, %ecx
	jne	.L16
	call	abort
.L16:
	movzbl	(%eax), %eax
	movb	%al, 536(%esp,%edx)
	leal	536(%esp), %eax
	addl	1048(%esp), %eax
	movl	%esi, %edx
	movl	%eax, %ecx
	testl	%ecx, %ecx
	jne	.L17
	call	abort
.L17:
	movb	%dl, (%eax)
.L5:
	movl	%esi, %eax
	cmpb	%al, %bl
	jge	.L6
	leal	24(%esp), %edx
	addl	1048(%esp), %edx
	movl	%edx, %ecx
	testl	%ecx, %ecx
	jne	.L18
	call	abort
.L18:
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
	movl	%ecx, %esi
	testl	%esi, %esi
	jne	.L19
	call	abort
.L19:
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
	movl	%eax, %edx
	testl	%edx, %edx
	jne	.L20
	call	abort
.L20:
	movzbl	(%eax), %eax
	movsbl	%al, %ebx
	leal	536(%esp), %eax
	addl	1052(%esp), %eax
	movl	%eax, %edx
	testl	%edx, %edx
	jne	.L21
	call	abort
.L21:
	movzbl	(%eax), %eax
	movsbl	%al, %ecx
	leal	792(%esp), %eax
	addl	1052(%esp), %eax
	movl	%eax, %edx
	testl	%edx, %edx
	jne	.L22
	call	abort
.L22:
	movzbl	(%eax), %eax
	movsbl	%al, %edx
	movl	$.LC0, %eax
	movl	%ebx, 12(%esp)
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%esp, %edx
	testl	%edx, %edx
	jne	.L23
	call	abort
.L23:
	movl	%eax, (%esp)
	call	printf
	addl	$1, 1052(%esp)
.L10:
	cmpl	$255, 1052(%esp)
	jle	.L11
	ret
	.size	main, .-main
