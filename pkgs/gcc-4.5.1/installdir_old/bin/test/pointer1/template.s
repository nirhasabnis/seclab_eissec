	.file	"template.c"
	.section	.rodata
.LC0:
	.string	"\n In func"
	.text
.globl func
	.type	func, @function
func:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	$.LC0, %eax
	movl	%eax, (%esp)
	call	printf
	leave
	ret
	.size	func, .-func
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	call	func
	movl	$0, %eax
	movl	%ebp, %esp
	popl	%ebp
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.4.3-4ubuntu5) 4.4.3"
	.section	.note.GNU-stack,"",@progbits
