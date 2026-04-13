#ifndef __C_Ops__
#define __C_Ops__

#include "stdlib.h"
#include "stdio.h"

// return the count of 1 in x in binary
int C_bitCount(int x);

// return a bitmask, from lowbit to highbit are 1, others are 0
int C_bitMask(int n, int m);

// return 1 if x + y overflow, else return 0
int C_addOK(int x, int y);

// return the value after x's n th byte exchanges with x's m th byte. n, m are from 0 ~ 3
int C_byteSwap(int x, int n, int m);

// return 1 if x has odd count of 0 in binary x, else return 0;
int C_bitParity(int x);

#endif