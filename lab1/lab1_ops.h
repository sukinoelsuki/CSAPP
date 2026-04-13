#ifndef __lab1_ops__
#define __lab1_ops__

#include "stdio.h"
#include "stdlib.h"
#include "lab1_stu.h"

int pack_student_bytebybyte(student_t* s, int sno, char* buf);
int pack_student_whole(student_t* s, int sno, char* buf);
int restore_student(char* buf, int len, student_t* s);

#endif