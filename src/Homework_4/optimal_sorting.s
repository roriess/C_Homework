  GNU nano 6.2          /home/vboxuser/work/optimal_sorting.s *                 
.L17:
        addl    $1, -592(%rbp)
.L15:
        cmpl    $99, -592(%rbp)
        jg      .L16
        movl    -592(%rbp), %eax
        cltq
        movl    -560(%rbp,%rax,4), %eax
        testl   %eax, %eax
        jne     .L17
.L16:
        movl    -592(%rbp), %eax
        movslq  %eax, %rdx
        subq    $1, %rdx
        movq    %rdx, -576(%rbp)
        movslq  %eax, %rdx
        movq    %rdx, %r14
        movl    $0, %r15d
        movslq  %eax, %rdx
        movq    %rdx, %r12
        movl    $0, %r13d
        cltq
        leaq    0(,%rax,4), %rdx
        movl    $16, %eax
        subq    $1, %rax
        addq    %rdx, %rax
        movl    $16, %esi
        movl    $0, %edx
        divq    %rsi
        imulq   $16, %rax, %rax
        movq    %rax, %rcx
        andq    $-4096, %rcx
        movq    %rsp, %rdx
        subq    %rcx, %rdx
.L18:
        cmpq    %rdx, %rsp
        je      .L19
        subq    $4096, %rsp
        orq     $0, 4088(%rsp)
        jmp     .L18
.L19:
        movq    %rax, %rdx
        andl    $4095, %edx
        subq    %rdx, %rsp
        movq    %rax, %rdx
        andl    $4095, %edx
        testq   %rdx, %rdx
        je      .L20
        andl    $4095, %eax
        subq    $8, %rax
        addq    %rsp, %rax
        orq     $0, (%rax)
.L20:
        movq    %rsp, %rax
        addq    $3, %rax
        shrq    $2, %rax
        salq    $2, %rax
        movq    %rax, -568(%rbp)
        movl    $0, -588(%rbp)
        jmp     .L21
.L22:
        movl    -588(%rbp), %eax
        cltq
        movl    -560(%rbp,%rax,4), %ecx
        movq    -568(%rbp), %rax
        movl    -588(%rbp), %edx
        movslq  %edx, %rdx
        movl    %ecx, (%rax,%rdx,4)
        addl    $1, -588(%rbp)
.L21:
        movl    -588(%rbp), %eax
        cmpl    -592(%rbp), %eax
        jl      .L22
        movl    -592(%rbp), %edx
        leaq    -560(%rbp), %rax
        movl    %edx, %esi
        movq    %rax, %rdi
        call    optimal_sorting
        movl    $0, -584(%rbp)
        movl    $0, -580(%rbp)
        jmp     .L23
.L25:
        movq    -568(%rbp), %rax
        movl    -580(%rbp), %edx
        movslq  %edx, %rdx
        movl    (%rax,%rdx,4), %edx
        movl    -580(%rbp), %eax
        cltq
        movl    -560(%rbp,%rax,4), %eax
        cmpl    %eax, %edx
        je      .L24
        addl    $1, -584(%rbp)
.L24:
        addl    $1, -580(%rbp)
.L23:
        movl    -580(%rbp), %eax
        cmpl    -592(%rbp), %eax
        jl      .L25
        movl    -584(%rbp), %eax
        movl    %eax, %esi
        leaq    .LC1(%rip), %rax
        movq    %rax, %rdi
        movl    $0, %eax
        call    printf@PLT
        movl    $0, %eax
        movq    %rbx, %rsp
        movq    -56(%rbp), %rdx
        subq    %fs:40, %rdx
        je      .L27
        call    __stack_chk_fail@PLT
.L27:
        leaq    -40(%rbp), %rsp
        popq    %rbx
        popq    %r12
        popq    %r13
        popq    %r14
        popq    %r15
        popq    %rbp
        .cfi_def_cfa 7, 8
        ret
        .cfi_endproc
.LFE2:
        .size   main, .-main
        .ident  "GCC: (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0"
        .section        .note.GNU-stack,"",@progbits
        .section        .note.gnu.property,"a"
        .align 8
        .long   1f - 0f
        .long   4f - 1f
        .long   5
0:
        .string "GNU"
1:
        .align 8
        .long   0xc0000002
        .long   3f - 2f
2:
        .long   0x3
3:
        .align 8
4:
