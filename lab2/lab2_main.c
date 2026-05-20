#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "lab2_stu.h"

#define Time_Anyfunc(afuncall)  ({ \
    LARGE_INTEGER start, finish, frequency; \
    double duration; \
    QueryPerformanceFrequency(&frequency); \
    QueryPerformanceCounter(&start); \
    afuncall; \
    QueryPerformanceCounter(&finish); \
    duration = ((double)(finish.QuadPart - start.QuadPart) * 1000.0) / (double)frequency.QuadPart; \
    printf("[计时器] 执行 %s 耗时: %f 毫秒 \n", #afuncall, duration); \
    duration; \
})


//#define __DEBUG_NUM__
#define STUDENTS_NUM  10

#pragma pack(push, 2)
typedef struct temp {
    char  sname[8];
    char  sid[11];     // 如 U202315123
    short  scores[8];  // 8 门课的分数
    short  average;    // 平均分
} student;
#pragma pack(pop)

void display(student *s, int num) {
	#ifndef __DEBUG_NUM__
    printf("==================================\n");
    printf("Displaying every student's info\n");
    for(int i = 0; i < num; ++i) {
        printf("%s %s %d %d %d %d %d %d %d %d average_score : %d\n", s[i].sname, s[i].sid,
               s[i].scores[0], s[i].scores[1], s[i].scores[2], s[i].scores[3],
               s[i].scores[4], s[i].scores[5], s[i].scores[6], s[i].scores[7],
               s[i].average);
    }
    printf("==================================\n\n");
	
	#else 
	#endif
}

void initStudents(student* s, int num)
{
    strcpy(s[0].sname, "Le0n3rd");
    strcpy(s[0].sid, "U202115634");
    for(int i = 0; i < 8; ++i) {
        s[0].scores[i] = rand() % 80 + i;
    }
    s[0].average = 0;

    for(int i = 1; i < num; ++i) {
        s[i].sname[0] = i + 'A' - 1;
        s[i].sname[1] = '\0';
        snprintf(s[i].sid, sizeof(s[i].sid), "U2021%05d", (unsigned int)(i % 100000));
        s[i].sid[10] = 0;
        
        for (int j = 0; j < 8; ++j) {
            s[i].scores[j] = rand() % 80 + j; 
        }
        s[i].average = 0;
    }
}

static inline void swapStudent(student* a, student* b) {
    student temp = *a;
    *a = *b;
    *b = temp;
}

// 简单冒泡（降序）
void sortStudentByAverageScore(student* s, int num)
{
    for(int i = 0; i < num; i++) {
        int swapped = 0;
        for(int j = 0; j < num - i - 1; j++) {
            if(s[j].average < s[j + 1].average) {
                swapStudent(&s[j], &s[j + 1]);
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
}

void heapify(student *s, int num, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < num && s[left].average < s[smallest].average) {
        smallest = left;
    }
    if (right < num && s[right].average < s[smallest].average) {
        smallest = right;
    }
    if (smallest != i) {
        swapStudent(&s[i], &s[smallest]);
        heapify(s, num, smallest);
    }
}

void heapsortStudentByAverageScore(student* s, int num) {
	
    for (int i = num / 2 - 1; i >= 0; i--) {
        heapify(s, num, i);
    }
	
    for (int i = num - 1; i > 0; i--) {
        swapStudent(&s[0], &s[i]);
        heapify(s, i, 0);
    }
}

// 引用外部汇编文件中的函数
extern void computeAverageScore(student *s, int num);
extern void computeAverageScoreOptimized(student *s, int num);

void computeAverageScore_C(student *s, int num) {
    for (int i = 0; i < num; ++i) {
        int sum = 0;
        for (int j = 0; j < 8; ++j) {
            sum += s[i].scores[j];
        }
        s[i].average = sum / 8;
    }
}

int main()
{
	// 解决编码问题，强行置控制台编码为 UTF-8
	SetConsoleOutputCP(65001); 
    SetConsoleCP(65001);

    srand((unsigned int)time(0));

    student s[STUDENTS_NUM];
    double sort_t1, sort_t2;

    initStudents(s, STUDENTS_NUM);         // 初始化学生信息
    display(s, STUDENTS_NUM);
    s[0] = s[1];
    display(s, STUDENTS_NUM);

	
    Time_Anyfunc(computeAverageScore_C(s, STUDENTS_NUM));

    printf("Before Bubble Sort:\n");
    display(s, STUDENTS_NUM);
    sort_t1 = Time_Anyfunc(sortStudentByAverageScore(s, STUDENTS_NUM));
    printf("After Bubble Sort:\n");
    display(s, STUDENTS_NUM);

    // 比较汇编优化前后效率
    double t1, t2;
    initStudents(s, STUDENTS_NUM);
    t1 = Time_Anyfunc(computeAverageScore(s, STUDENTS_NUM)); 

    initStudents(s, STUDENTS_NUM);
    t2 = Time_Anyfunc(computeAverageScoreOptimized(s, STUDENTS_NUM));
    printf("比较汇编代码优化：\n");
    printf("优化前耗时：%lf 毫秒    优化后耗时：%lf 毫秒\n", t1, t2);
    printf("加速比为：%0.4lf\n\n", t1 / t2);

    // 【基准测试依赖修正 4】因为上面 initStudents 重新把 average 刷成了 0
    // 如果直接跑排序毫无意义。这里先跑一次优化后的汇编计算，再跑堆排序测试
    computeAverageScoreOptimized(s, STUDENTS_NUM);

    // 3. 测试堆排序耗时
    sort_t2 = Time_Anyfunc(heapsortStudentByAverageScore(s, STUDENTS_NUM));
    printf("After Heap Sort:\n");
    display(s, STUDENTS_NUM);

    printf("比较不同排序方法耗时：\n");
    printf("冒泡排序耗时：%lf 毫秒\n堆排序耗时：%lf 毫秒\n", sort_t1, sort_t2);
	printf("加速比为：%0.4lf\n\n", sort_t1 / sort_t2);

	system("PAUSE");

    return 0;
}