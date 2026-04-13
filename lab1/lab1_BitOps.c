#include "lab1_BitOps.h"


// What if x is under 0, will (~(x >> 31) + 1) work?
int absVal(int x) {
    return x ^ (x >> 31) + (~(x >> 31) + 1);
}

int negate(int x) {
    return (~x) + 1;
}

int bitAnd(int x, int y) {
    return ~((~x) | (~y));
}

int bitOr(int x, int y) {
    return ~((~x) & (~y));
}

int bitXor(int x, int y) {
    return (~(~x & ~y) & ~(x & y));
}

int isTmax(int x) {
    return bitXor(x, 0x7fffffff);
}

int bitCount(int x) {
    int cnt = 0;
    while (x) {
        cnt += x & 1;
        x >>= 1;
    }
    return cnt;
}

int bitMask(int highbit, int lowbit) {
    return (int)((unsigned long long)1 << (highbit + 1)) + (~(unsigned long long)(1 << lowbit) + 1);
}

// ?
int addOK(int x, int y) {
    return !((((x ^ y) >> 31) & 1) | (((x & y) >> 30) & 1));
}

int byteSwap(int x, int n, int m) {
    x ^ (((x & (0x000000ff << (n << 2))) >> (n << 2)) << (m << 2));
    x ^ (((x & (0x000000ff << (m << 2))) >> (m << 2)) << (n << 2));
    x ^ (((x & (0x000000ff << (n << 2))) >> (n << 2)) << (m << 2));
    return x;
}

int bang(int x) {
    return ((~(x & 0x80000000) & ~(negate(x) & 0x80000000)) >> 31) & 1;
}

int bitParity(int x) {
    unsigned int ans = x;
    ans = (ans >> 16) ^ ans;
    ans = (ans >> 8) ^ ans;
    ans = (ans >> 4) ^ ans;
    ans = (ans >> 2) ^ ans;
    ans = (ans >> 1) ^ ans;
    return ans;
}