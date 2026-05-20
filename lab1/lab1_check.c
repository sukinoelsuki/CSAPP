#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#include "lab1_ops.h"
#include "lab1_check.h"
#include "lab1_C_Ops.h"
#include "lab1_BitOps.h"

#define RANDOM (get_my_random_Number())
#define ABS(x) (((x) > 0) ? (x) : -(x))

static inline void print_N_student(student_t *s, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%s %hd %0.2f %s\n", s[i].name, s[i].age, s[i].score, s[i].remark);
    }
    printf("\n");
}

/*
Le0n3rd 20 95.5 U202115634   
Bob 21 88.0 B-
Cathy 22 76.3 C
David 23 100.0 A
Eve 24 60.0 F
*/

int do_check_compress(student_t* s, char* buf, student_t* t) {

    memset(s, 0, MAX_BYTE * MAX_NUM);
    memset(t, 0, MAX_BYTE * MAX_NUM);
    memset(buf, 0, MAX_BYTE * MAX_NUM + 5);
    printf("Please input students' info\n");
    for (int i = 0; i < 5; ++i) {
        scanf("%8s %hd %f %200s", s[i].name, &s[i].age, &s[i].score, s[i].remark);
    }

    printf("Before compress:\n");
    print_N_student(s, 5);

    pack_student_bytebybyte(s, 3, buf);
    pack_student_whole(s + 3, 2, buf + 3 * MAX_BYTE);
    restore_student(buf, MAX_NUM * MAX_BYTE, t);

    printf("After compress:\n");
    print_N_student(t, 5);

    return 0;
}

static inline void is_the_same(int x, int y) {
    printf("My result is %d, the correct result is %d\n", x, y);
    if (x == y) {
        printf("The result is correct!\n");
    } else {
        printf("Something wrong with my answer.\n");
    }
    printf("\n");
}

// the return value of rand is 15 bits
static inline int get_my_random_Number() {
    unsigned int val = 0;
    val |= ((unsigned int)rand() << 17);
    val |= ((unsigned int)rand() << 2);
    val |= ((unsigned int)rand() & 0x03);
    printf("RANDOM NUMBER : %d\n", val);
    return (int)val;
}

void check_BitOps() {

    srand((unsigned int)time(NULL));
    int x, y, m, n;

    printf("Checking absVal with random test...\n");
    x = RANDOM;
    is_the_same(absVal(x), ABS(x));

    printf("Checking negate with random test...\n");
    x = RANDOM;
    is_the_same(negate(x), -x);

    printf("Checking bitAnd with random test...\n");
    x = RANDOM, y = RANDOM;
    is_the_same(bitAnd(x, y), x & y);

    printf("Checking bitOr with random test...\n");
    x = RANDOM, y = RANDOM;
    is_the_same(bitOr(x, y), x | y);

    printf("Checking bitXor with random test...\n");
    x = RANDOM, y = RANDOM;
    is_the_same(bitXor(x, y), x ^ y);

    printf("Checking isTmax with random test...\n");
    x = RANDOM;
    is_the_same(isTmax(x), (x == 0x7fffffff));

    printf("Checking bitCount with random test...\n");
    x = RANDOM;
    is_the_same(bitCount((unsigned int)x), C_bitCount((unsigned int)x));

    // n >= m
    printf("Checking bitMask with random test...\n");
    n = (RANDOM % 32 + 32) % 32, m = (RANDOM % 32 + 32) % 32;
    n = (m <= n ? n : m);
    is_the_same(bitMask(n, m), C_bitMask(n, m));

    printf("Checking addOK with random test...\n");
    x = RANDOM, y = RANDOM;
    is_the_same(addOK(x, y), C_addOK(x, y));

    //Same way to accomplish
    printf("Checking byteSwap with random test...\n");
    x = RANDOM, n = ((RANDOM % 4) + 4) % 4, m = (RANDOM % 4 + 4) % 4;
    is_the_same(byteSwap(x, n, m), byteSwap(x, n, m));

    printf("Checking bang with random test...\n");
    x = RANDOM;
    is_the_same(bang(x), (x == 0)); 

    printf("Checking bitParity with random test...\n");
    x = RANDOM;
    is_the_same(bitParity(x), C_bitParity(x));


}

int do_check_BitOps() {

    printf("Camparing BitOps with C Stanard Library Functions...\n\n");

    check_BitOps();

    return 0;
}