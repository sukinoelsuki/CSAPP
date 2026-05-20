#ifndef __lab1_student__
#define __lab1_student__

#define MAX_BYTE 216
#define MAX_NUM 5

// 巴菲特法则，降序排列
typedef struct student {
    float score;          // 4 bytes
    short age;            // 2 bytes
    char name[8];         // 1 * 8 bytes
    char remark[200];     // 1 * 200 bytes

} student_t;              // 8 + 2 + 4 + 200 + 2(padding) = 216 bytes



#endif