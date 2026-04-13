#include "lab1_C_Ops.h"
#include "math.h"

int C_bitCount(int x) {
    int cnt = 0;
    while (x) {
        if (x % 2) cnt++;
        x /= 2;
    }
    return cnt;
}

int C_bitMask(int n, int m) {
    int re = 0;
    for (int i = m; i <= n; ++i) {
        re += pow(2, i);
    }
    return re;
}

int C_addOK(int x, int y) {
    int re = x + y;
    if ((x > 0 && y > 0 && re <= 0) || (x < 0 && y < 0 && re >= 0)) {
        return 1;
    }
    return 0;
}

// Actually the same way in byteSwap
int C_byteSwap(int x, int n, int m) {

    return 0;
}

/*
int C_bitParity(int x) {
    int cnt = 0;
    if (x == 0)  return 1;
    while(x) {
        if (!(x % 2)) {
            cnt ++;
        }
        x /= 2;
    }
    return (cnt % 2) == 0 ? 0 : 1;
}
*/

int C_bitParity(int x) {
    return C_bitCount(x) % 2;
}