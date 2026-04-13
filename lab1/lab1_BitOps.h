#ifndef __BitOps__
#define __BitOps__

#include "stdio.h"
#include "stdlib.h"

// return the absolute value of x
int absVal(int x);

// return -x 
int negate(int x);

// return x & y , only use ~ and |
int bitAnd(int x, int y);

// return x | y , only use ~ and &
int bitOr(int x, int y);

// return x Xor y , only use ~ and &
int bitXor(int x, int y);

// tell if x is the largest number 7FFFFFFF
int isTmax(int x);

// return the count of 1 in x in binary
int bitCount(int x);

// return a bitmask, from lowbit to highbit are 1, others are 0
int bitMask(int highbit, int lowbit);

// return 1 if x + y overflow, else return 0
int addOK(int x, int y);

// return the value after x's n th byte exchanges with x's m th byte. n, m are from 0 ~ 3
int byteSwap(int x, int n, int m);

// return 1 when x equals 0, else return 0
int bang(int x);

// return 1 if x has odd count of 0 in binary x, else return 0;(The definition in the guidance file is ambiguous.)
int bitParity(int x);


#endif