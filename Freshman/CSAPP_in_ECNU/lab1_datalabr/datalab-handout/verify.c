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

int isPositive(int x) {
  return ((x >> 31) + 1) && (x ^ 0);
}

int isLessOrEqual(int x, int y) {
  int subtraction = y + (~x + 1);

  return ((subtraction >> 31) + 1);
}

unsigned float_neg2(unsigned uf) {
  int c=0x00ffffff;
  if(((uf<<1)^(0xffffffff))<c){
    return uf;
  }else{
    return uf^(0x80000000);
  }
}

unsigned float_neg(unsigned uf){
  unsigned int sign = (uf >> 31) ^ 0;    // if MSB is 1, then sign = 1 , else sign = 0

  unsigned int result = 0;

  if(sign == 1)
    result = uf - 2147483648;
  else  result = uf + 2147483648;


  if(((uf >> 23) == 255) && ((uf << 9) != 0)) result = uf;
  return result;
}

int main(){
    int a = 0xFFFFFFFF;


    printf("%u\n", float_neg(a));
    printf("%u\n", float_neg2(a));
    printf("%u\n", a);

}