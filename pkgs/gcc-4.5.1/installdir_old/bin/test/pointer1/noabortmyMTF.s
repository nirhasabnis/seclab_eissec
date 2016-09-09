	.file	"myMTF.c"
	.section	.rodata
.LC0:
	.string	"%2x"
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
	subl	$308, %esp
	movb	$-22, 299(%esp)
	movl	$0, 300(%esp)
	jmp	.L2
.L3:
	addl	$1, 300(%esp)
.L2:
	cmpl	$255, 300(%esp)
	jle	.L3
	movzbl	44(%esp), %ebx
	leal	43(%esp), %eax
	leal	1(%eax), %esi
	jmp	.L4
.L5:
	addl	$1, %esi
	movl	%ebx, %edi
	movl	%edi, %eax
	cmpb	$-18, %al
	sete	31(%esp)
	movzbl	43(%esp), %eax
	movzbl	%al, %edx
	movl	$.LC0, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	cmpb	$0, 31(%esp)
	je	.L4
	movzbl	(%esi), %ebx
	movl	%edi, %eax
	movb	%al, (%esi)
.L4:
	cmpb	299(%esp), %bl
	jne	.L5
	movb	%bl, 43(%esp)
	movzbl	43(%esp), %eax
	movzbl	%al, %edx
	movl	$.LC0, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	ret
	.size	main, .-main
