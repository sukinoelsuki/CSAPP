#ifndef STUDENT_H
#define STUDENT_H

#define SCORES_NUM    8
#define STUDENT_SIZE  38  // 8(sname) + 11(sid) + 1(padding) + 16(scores) + 2(average)

#ifndef __ASSEMBLER__

typedef struct temp {
    char  sname[8];
    char  sid[11];     
    short scores[8];  
    short average;    
} student;

#endif

#define OFS_STUDENT_SCORES  20
#define OFS_STUDENT_AVERAGE 36

#endif // STUDENT_H