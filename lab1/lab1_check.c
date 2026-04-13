#include "lab1_check.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "lab1_ops.h"

void print_N_student(student_t *s, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%s %hd %f %s\n", s[i].name, s[i].age, s[i].score, s[i].remark);
    }
}

int do_check_storage(student_t* s, char* buf, student_t* t) {

    memset(s, 0, MAX_BYTE);
    memset(t, 0, MAX_BYTE);
    memset(buf, 0, MAX_BYTE + 5);
    printf("Please input students' info\n");
    for (int i = 0; i < 5; ++i) {
        scanf("%s%hd%f%s", &s[i].name, &s[i].age, &s[i].score, &s[i].remark);
    }

    print_N_student(s, 5);

    pack_student_bytebybyte(s, 3, buf);
    pack_student_whole(s, 2, buf + 3 * sizeof(student_t));
    restore_student(buf, 5, t);

    print_N_student(t, 5);

    return 0;
}

int do_check_BitOps() {

    printf("Please a number to use the fuction below:\n");

    int choice = 0;
    while (1) {
        scanf("%d", &choice);
        switch (choice) {
            case 0: {
                printf("Exiting from BitOps_Check...");
                return 0;
            }
            case 1:
              break;
            
            default:
              break;
        }
    }
    return 0;
}