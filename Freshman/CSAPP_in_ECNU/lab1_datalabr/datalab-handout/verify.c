#include <stdio.h>




unsigned float_neg23(unsigned uf) {
  int c=0x00ffffff;
  if(((uf<<1)^(0xffffffff))<c){
    return uf;
  }else{
    return uf^(0x80000000);
  }
}

unsigned float_neg(unsigned uf){

    if( (~ (uf << 1)) < 0x00ffffff) return uf;
    else return uf ^ (1 << 31);
}

unsigned float_i2f(int x) {

  int sign = x >> 31 & 1;
  int i = 30, exponent, fraction, delta;

  if(x == 0)  return 0;
  if( x == 0x80000000) exponent = 158;
  else{
    if (sign) x = -x; // turn negative to positive

    while( !(x >> i)) i--;// find out how many valid bits does x have

    exponent = i + 127;     // IEEE standard
    x = x << (31 - i);      // clear the higher bits zero

    fraction = (0x7fffff) & (x >> 8);
    x = x & 0xff;
    delta = x > 128 || ((x == 128) && (fraction & 1)); // if lowest 8 bits of x is larger than a half, round up 1

    if((fraction + delta) >> 23) {
      fraction = (fraction + delta) & 0x7fffff;
      exponent += 1;
    }
  }

  return (sign << 31) | (exponent << 23) | fraction;
}

int main(){
    int a = 0xFFFFFFFF;


    printf("%u\n", float_i2f(15213));



}