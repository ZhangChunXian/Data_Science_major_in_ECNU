#include <stdio.h>


    int logicalShift(int x, int n) {
    /* The function is used to shift x to the right by n, using a logical shift*/
    int mask1 = (1 << 31) >> 31;        // mask1 = 111..11(all 0 in 32bit)

    int mask2 = (1 << 31) >> (n + (-1));   // mask2 = 1..1(n 1) 00..0(32-n 0)

    int mask3 = (mask1 ^ mask2);          // mask3 = 00..0(n 0) 11..1(32-n 0)

    return (x >> n) & mask3;

    }
int main(){
    int a = 0xFFFFFFFF;

    printf("%x\n", logicalShift(a, 4));

    printf("%x\n", logicalShift(a, 8));

    printf("%x\n", logicalShift(a, 12));

    printf("%x\n", logicalShift(a, 16));

    printf("%x\n", logicalShift(a, 20));

    return 0;
}