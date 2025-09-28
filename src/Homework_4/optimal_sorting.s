	.file	"optimal_sorting.c"
	.text
	.globl	strToArr
	.type	strToArr, @function
strToArr:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movl	$0, -24(%rbp)
	movl	$0, -20(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movq	%rax, -8(%rbp)
	movq	$0, -16(%rbp)
	jmp	.L2
.L5:
	movq	-40(%rbp), %rdx
	movq	-16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$47, %al
	jle	.L3
	movq	-40(%rbp), %rdx
	movq	-16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$57, %al
	jg	.L3
	movl	-24(%rbp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movl	%eax, %ecx
	movq	-40(%rbp), %rdx
	movq	-16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	subl	$48, %eax
	addl	%ecx, %eax
	movl	%eax, -24(%rbp)
	jmp	.L4
.L3:
	cmpl	$0, -24(%rbp)
	jle	.L4
	movl	-20(%rbp), %eax
	leal	1(%rax), %edx
	movl	%edx, -20(%rbp)
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-48(%rbp), %rax
	addq	%rax, %rdx
	movl	-24(%rbp), %eax
	movl	%eax, (%rdx)
	movl	$0, -24(%rbp)
.L4:
	addq	$1, -16(%rbp)
.L2:
	movq	-40(%rbp), %rdx
	movq	-16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L5
	cmpl	$0, -24(%rbp)
	jle	.L7
	movl	-20(%rbp), %eax
	leal	1(%rax), %edx
	movl	%edx, -20(%rbp)
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-48(%rbp), %rax
	addq	%rax, %rdx
	movl	-24(%rbp), %eax
	movl	%eax, (%rdx)
.L7:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	strToArr, .-strToArr
	.type	compare_ints, @function
compare_ints:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movl	(%rax), %edx
	movq	-16(%rbp), %rax
	movl	(%rax), %ecx
	movl	%edx, %eax
	subl	%ecx, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	compare_ints, .-compare_ints
	.section	.rodata
.LC0:
	.string	"%99[^\n]"
.LC1:
	.string	"%d"
	.text
	.globl	main
	.type	main, @function
main:
.LFB8:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$552, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
	movq	%fs:40, %rax
	movq	%rax, -56(%rbp)
	xorl	%eax, %eax
	movq	%rsp, %rax
	movq	%rax, %rbx
	leaq	-160(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	leaq	-560(%rbp), %rax
	movl	$400, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
	leaq	-560(%rbp), %rdx
	leaq	-160(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strToArr
	movl	$0, -588(%rbp)
	jmp	.L11
.L12:
	addl	$1, -588(%rbp)
.L11:
	movl	-588(%rbp), %eax
	cltq
	movl	-560(%rbp,%rax,4), %eax
	testl	%eax, %eax
	jne	.L12
	movl	-588(%rbp), %eax
	movslq	%eax, %rdx
	subq	$1, %rdx
	movq	%rdx, -576(%rbp)
	movslq	%eax, %rdx
	movq	%rdx, %r14
	movl	$0, %r15d
	movslq	%eax, %rdx
	movq	%rdx, %r12
	movl	$0, %r13d
	cltq
	leaq	0(,%rax,4), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %edi
	movl	$0, %edx
	divq	%rdi
	imulq	$16, %rax, %rax
	movq	%rax, %rcx
	andq	$-4096, %rcx
	movq	%rsp, %rdx
	subq	%rcx, %rdx
.L13:
	cmpq	%rdx, %rsp
	je	.L14
	subq	$4096, %rsp
	orq	$0, 4088(%rsp)
	jmp	.L13
.L14:
	movq	%rax, %rdx
	andl	$4095, %edx
	subq	%rdx, %rsp
	movq	%rax, %rdx
	andl	$4095, %edx
	testq	%rdx, %rdx
	je	.L15
	andl	$4095, %eax
	subq	$8, %rax
	addq	%rsp, %rax
	orq	$0, (%rax)
.L15:
	movq	%rsp, %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -568(%rbp)
	movl	-588(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	-560(%rbp), %rcx
	movq	-568(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	memcpy@PLT
	movl	-588(%rbp), %eax
	movslq	%eax, %rsi
	leaq	-560(%rbp), %rax
	leaq	compare_ints(%rip), %rdx
	movq	%rdx, %rcx
	movl	$4, %edx
	movq	%rax, %rdi
	call	qsort@PLT
	movl	$0, -584(%rbp)
	movl	$0, -580(%rbp)
	jmp	.L16
.L18:
	movq	-568(%rbp), %rax
	movl	-580(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %edx
	movl	-580(%rbp), %eax
	cltq
	movl	-560(%rbp,%rax,4), %eax
	cmpl	%eax, %edx
	je	.L17
	addl	$1, -584(%rbp)
.L17:
	addl	$1, -580(%rbp)
.L16:
	movl	-580(%rbp), %eax
	cmpl	-588(%rbp), %eax
	jl	.L18
	movl	-584(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	movq	%rbx, %rsp
	movq	-56(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L20
	call	__stack_chk_fail@PLT
.L20:
	leaq	-40(%rbp), %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
