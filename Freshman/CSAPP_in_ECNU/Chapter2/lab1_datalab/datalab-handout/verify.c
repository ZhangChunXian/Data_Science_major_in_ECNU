#include <stdio.h>


int getByte(int x, int n) {
    /* The function is used to extract byte from word*/
    int shift_number = n << 3;

    int temp = (0xFF << shift_number);

    temp = x & temp;
	
    int Extracted_byte = (temp >> shift_number ) & 0xFF;    

    return Extracted_byte;

}

int logicalShift(int x, int n) {
/* The function is used to shift x to the right by n, using a logical shift*/
	int mask1 = (1 << 31) >> 31;        // mask1 = 111..11(all 1 in 32bit)

	int mask2 = (1 << 31) >> (n + (~x + x));   // mask2 = 1..1(n 1) 00..0(32-n 0)

	int mask3 = (mask1 ^ mask2);          // mask3 = 00..0(n 0) 11..1(32-n 0)

	return (x >> n) & mask3;

}

int bitCount(int x) {
	int bits = 0, mask;
	mask = 0x1 | (0x1 << 8) | (0x1 << 16) | (0x1 << 24);

	bits = bits + (x & mask);
	bits = bits + ((x >> 1) & mask);
	bits = bits + ((x >> 2) & mask);
	bits = bits + ((x >> 3) & mask);
	bits = bits + ((x >> 4) & mask);
	bits = bits + ((x >> 5) & mask);
	bits = bits + ((x >> 6) & mask);
	bits = bits + ((x >> 7) & mask);
	return (bits & 0xFF) + ((bits >> 8) & 0xFF) + ((bits >> 16) & 0xFF) + ((bits >> 24) & 0xFF);
}

int bang(int x) {
   /* the function is used to compute !x without using ! */
    x = (x >> 16) | x;
    x = (x >> 8) | x;
    x = (x >> 4) | x;
    x = (x >> 2) | x;
    x = (x >> 1) | x;
    return ~x & 1;
}

int divpwr2(int x, int n) {
	/* The function is used to compute x/(2^n) round toward zero */
	
	int mask1 = x >> 31;

	int mask2 = (1 << n) + ~0;

	return (x + (mask1 & mask2)) >> n;
}

int negate(int x) {
	/* The function is used to compute -x */
	return ~x + 1;

}

int isPositive(int x) {
	return ((x >> 31) + 1) & !(!x);
}

int isLessOrEqual(int x, int y) {
	int subtraction = y + (~x + 1);
	return ((subtraction >> 31) + 1);
}

int ilog2(int x) {
	int mask1, mask2, mask3, mask4, mask5;
	x = x | (x >> 1);
	x = x | (x >> 2);
	x = x | (x >> 4);
	x = x | (x >> 8);
	x = x | (x >> 16);


	mask1 = ((0x55 << 8 | 0x55) << 16) | (0x55 << 8 | 0x55);

	mask2 = ((0x33 << 8 | 0x33) << 16) | (0x33 << 8 | 0x33);

	mask3 = ((0x0F << 8 | 0x0F) << 16) | (0x0F << 8 | 0x0F);

	mask4 = 0xFF << 16 | 0xFF;

	mask5 = 0xFF << 8 | 0xFF;

	x = (x & mask1) + ((x >> 1) & mask1);

	x = (x & mask2) + ((x >> 2) & mask2);

	x = (x & mask3) + ((x >> 4) & mask3);

	x = (x & mask4) + ((x >> 8) & mask4);

	x = (x & mask5) + ((x >> 16) & mask5);
	return x + (~1) + 1;
}

unsigned float_neg(unsigned uf) {

	if( (~ (uf << 1)) < 0x00ffffff) return uf;
	else return uf ^ (1 << 31);
}

int fitsBits(int x, int n) {
    /* The function is used to test whether x can be  represented as an
  n-bit, two's complement integer. */
    return !(x ^ (x << (33 + ~n) >> (33 + ~n)));
}

int main(){
  printf("%d\n", fitsBits(5, 3));
  printf("%d", fitsBits(-4, 3));
}