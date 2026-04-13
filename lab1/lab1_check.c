#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "time.h"


#include "lab1_ops.h"
#include "lab1_check.h"
#include "lab1_C_Ops.h"
#include "lab1_BitOps.h"

#define RANDOM get_my_random_Number()
#define ABS(x) x > 0 ? x : -x 

void print_N_student(student_t *s, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%s %hd %f %s\n", s[i].name, s[i].age, s[i].score, s[i].remark);
    }
}

int do_check_compress(student_t* s, char* buf, student_t* t) {

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

void is_the_same(int x, int y) {
    printf("My result is %d, the correct result is %d\n", x, y);
    if (x == y) {
        printf("The result is correct!\n");
    } else {
        printf("Something wrong with my answer.\n");
    }
    printf("\n");
}

int get_my_random_Number() {
    unsigned int val = 0;
    val |= ((unsigned int)rand() << 17);
    val |= ((unsigned int)rand() << 2);
    val |= ((unsigned int)rand() & 0x03);
    return (int)val;
}

void check_BitOps() {

    srand((unsigned int)time(NULL));
    int x, y, m, n;

    printf("Checking absVal with random test...\n");
    is_the_same(absVal(x = RANDOM), ABS(x));

    printf("Checking negate with random test...\n");
    is_the_same(negate(x = RANDOM), -x);

    printf("Checking bitAnd with random test...\n");
    is_the_same(bitAnd(x = RANDOM, y = RANDOM), x & y);

    printf("Checking bitOr with random test...\n");
    is_the_same(bitOr(x = RANDOM, y = RANDOM), x | y);

    printf("Checking bitXor with random test...\n");
    is_the_same(bitXor(x = RANDOM, y = RANDOM), x ^ y);

    printf("Checking isTmax with random test...\n");
    is_the_same(isTmax(x = RANDOM), (x != 0x7fffffff));

    printf("Checking bitCount with random test...\n");
    is_the_same(bitCount(x = RANDOM), C_bitCount(x));

    printf("Checking bitMask with random test...\n");
    is_the_same(bitMask(n = RANDOM, m = RANDOM), C_bitMask(n, m));

    printf("Checking addOK with random test...\n");
    is_the_same(addOK(x = RANDOM, y = RANDOM), C_addOK(x, y));

    //Same way to accomplish
    printf("Checking byteSwap with random test...\n");
    is_the_same(byteSwap(x = RANDOM, n = RANDOM % 4, m = RANDOM % 4), byteSwap(x, n, m));

    printf("Checking bang with random test...\n");
    is_the_same(bang(x = RANDOM), (x == 0)); 

    printf("Checking bitParity with random test...\n");
    is_the_same(bitParity(x = RANDOM), C_bitParity(x));


}

int do_check_BitOps() {

    printf("Camparing BitOps with C Stanard Library Functions...\n");

    check_BitOps();

    return 0;
}