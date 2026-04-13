#include "lab1_ops.h"

int pack_a_student_bytebybyte(student_t* s, char* buf) {
    char* ptr = s;
    for (int i = 0; i < MAX_NUM; ++i) {
        s += i;
        *(buf + i) = *(ptr + i);
    }
    return 0;
}

// pack students by every byte
int pack_student_bytebybyte(student_t* s, int sno, char* buf) {
    int cnt;
    for (cnt = 0; cnt < sno; ++cnt) {
        pack_a_student_bytebybyte(&s[cnt], buf + cnt * sizeof(student_t));
    }
    return cnt;
}

// pack a student as a whole
int pack_student_whole(student_t* s, int sno, char* buf) {
    int cnt = 0;
    return cnt;
}

// restore student infos from specified buf
int restore_student(char* buf, int len, student_t* s) {
    int cnt = 0;
    return cnt;
}