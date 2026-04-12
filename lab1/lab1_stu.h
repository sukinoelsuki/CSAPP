#ifndef __lab1_student__
#define __lab1_student__

typedef struct student {
    char name[8];         // 8 bytes
    short age;            // 2 bytes
    float score;          // 4 bytes
    char remark[200];     // 200 bytes

} student_t;              // 8 + 2 + 4 + 200 = 214 bytes


#endif