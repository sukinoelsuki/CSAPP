.intel_syntax noprefix
#include "lab2_stu.h"

.global computeAverageScore
.text

computeAverageScore:
    cmp rdx, 0
    jle .L_done

    xor r8, r8

.L_outer_loop:
    cmp r8, rdx
    jge .L_done

    mov rax, r8
    imul rax, rax, STUDENT_SIZE
    add rax, rcx

    xor r9, r9
    xor r10, r10

.L_inner_loop:
    cmp r10, SCORES_NUM
    jge .L_inner_done

    movzx r11, word ptr [rax + OFS_STUDENT_SCORES + r10 * 2]
    add r9, r11

    inc r10
    jmp .L_inner_loop

.L_inner_done:
    sar r9, 3
    mov word ptr [rax + OFS_STUDENT_AVERAGE], r9w

    inc r8
    jmp .L_outer_loop

.L_done:
    ret