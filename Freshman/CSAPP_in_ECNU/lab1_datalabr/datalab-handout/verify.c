#include <stdio.h>


    int logicalShift(int x, int n) {
    /* The function is used to shift x to the right by n, using a logical shift*/
    int mask1 = (1 << 31) >> 31;        // mask1 = 111..11(all 0 in 32bit)

    int mask2 = (1 << 31) >> (n + (~x + x));   // mask2 = 1..1(n 1) 00..0(32-n 0)

    int mask3 = (mask1 ^ mask2);          // mask3 = 00..0(n 0) 11..1(32-n 0)

    return (x >> n) & mask3;

    }

int negate(int x) {
  return ~x + 1;
}
int divpwr2(int x, int n) {
    /* The function is used to Compute x/(2^n) Round toward zero*/
    int mask1 = x >> 31;

    int mask2 = (0x1 << n) + ~0;

    return (x + (mask1 & mask2)) >> n;
}

int main(){
    int a = 0xFFFFFFFF;

    printf("%d\n", negate(1));
    printf("%d\n", negate(2));
    printf("%d\n", negate(4));
    printf("%d\n", negate(8));
    printf("%d\n", negate(16));
    printf("%d\n", negate(32));
}