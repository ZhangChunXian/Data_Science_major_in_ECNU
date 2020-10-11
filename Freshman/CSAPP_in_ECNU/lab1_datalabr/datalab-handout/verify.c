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

int main(){
    int a = 0xFFFFFFFF;


    printf("%u\n", float_neg(a));
    printf("%u\n", float_neg23(a));
    printf("%u\n", a);

}