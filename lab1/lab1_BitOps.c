#include "lab1_BitOps.h"

// it works for both negatives and possitives.
// Use the difference of signiture to dicide whether negate the number of not.
int absVal(int x) {
    return (x ^ (x >> 31)) + (~(x >> 31) + 1);
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
    return !(bitXor(x, 0x7fffffff));
}

int bitCount(unsigned int x) {
    x = ((x & 0x55555555) + ((x >> 1) & 0x55555555));
    x = ((x & 0x33333333) + ((x >> 2) & 0x33333333));
    x = ((x & 0x0f0f0f0f) + ((x >> 4) & 0x0f0f0f0f));
    x = ((x & 0x00ff00ff) + ((x >> 8) & 0x00ff00ff));
    x = ((x & 0x0000ffff) + ((x >> 16) & 0x0000ffff));
    return x;
}

int bitMask(int highbit, int lowbit) {
    return (int)(((long long)1 << (highbit + 1)) + (~((long long)1 << lowbit) + 1));
}

int addOK(int x, int y) {
    return !(((x ^ y) >> 31) & 1) & ((x >> 31) ^ ((x + y) >> 31));
}

int byteSwap(int x, int n, int m) {
    x = x ^ (((x & (0x000000ff << (n << 2))) >> (n << 2)) << (m << 2));
    x = x ^ (((x & (0x000000ff << (m << 2))) >> (m << 2)) << (n << 2));
    x = x ^ (((x & (0x000000ff << (n << 2))) >> (n << 2)) << (m << 2));
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
    return (ans & 1);
}