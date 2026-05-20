.intel_syntax noprefix
#include "lab2_stu.h"

.global computeAverageScoreOptimized
.text

computeAverageScoreOptimized:
    cmp rdx, 0
    jle .L_done

.L_loop_students:
    movzx eax, word ptr [rcx + OFS_STUDENT_SCORES + 0]
    movzx r8d, word ptr [rcx + OFS_STUDENT_SCORES + 2]
    add eax, r8d
    movzx r8d, word ptr [rcx + OFS_STUDENT_SCORES + 4]
    add eax, r8d
    movzx r8d, word ptr [rcx + OFS_STUDENT_SCORES + 6]
    add eax, r8d
    movzx r8d, word ptr [rcx + OFS_STUDENT_SCORES + 8]
    add eax, r8d
    movzx r8d, word ptr [rcx + OFS_STUDENT_SCORES + 10]
    add eax, r8d
    movzx r8d, word ptr [rcx + OFS_STUDENT_SCORES + 12]
    add eax, r8d
    movzx r8d, word ptr [rcx + OFS_STUDENT_SCORES + 14]
    add eax, r8d

    shr eax, 3
    mov word ptr [rcx + OFS_STUDENT_AVERAGE], ax

    add rcx, STUDENT_SIZE
    dec rdx
    jnz .L_loop_students

.L_done:
    ret