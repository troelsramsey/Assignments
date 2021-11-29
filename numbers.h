#include <stdint.h>
#include "bits.h"

struct bits8 {
  struct bit b0; // Least significant bit
  struct bit b1;
  struct bit b2;
  struct bit b3;
  struct bit b4;
  struct bit b5;
  struct bit b6;
  struct bit b7;
};

struct bits8 bits8_from_int(unsigned int x) {
  struct bits8 b;  
  b.b7.v = x & (1 << 7);
  b.b6.v = x & (1 << 6);
  b.b5.v = x & (1 << 5);
  b.b4.v = x & (1 << 4);
  b.b3.v = x & (1 << 3);
  b.b2.v = x & (1 << 2);
  b.b1.v = x & (1 << 1);
  b.b0.v = x & 1;

  /*
  printf("Input: \t %u\n", x);

  x -= (x / (1 << 8)) * (1 << 8);       //Calculate 8bit input
  printf("8bit input: \t %u\n", x);
  b.b7.v = x / (1 << 7);                //Calculate b7
  printf("8th bit: \t %d\n", b.b7.v);
  
  x -= (1 << 7) * b.b7.v;               //Calculate 7bit input (Remove the 8th bit)
  printf("7bit input: \t %u\n", x);
  b.b6.v = x / (1 << 6);                //Calculate b6
  printf("7th bit: \t %d\n", b.b6.v);
  
  x -= (1 << 6) * b.b6.v;
  printf("6bit input: \t %u\n", x);
  b.b5.v = x / (1 << 5);
  printf("6th bit: \t %d\n", b.b5.v);
  
  x -= (1 << 5) * b.b5.v;
  printf("5bit input: \t %u\n", x);
  b.b4.v = x / (1 << 4);
  printf("5th bit: \t %d\n", b.b4.v);

  x -= (1 << 4) * b.b4.v;
  printf("4bit input: \t %u\n", x);
  b.b3.v = x / (1 << 3);
  printf("4th bit: \t %d\n", b.b3.v);

  x -= (1 << 3) * b.b3.v;
  printf("3bit input: \t %u\n", x);
  b.b2.v = x / (1 << 2);
  printf("3th bit: \t %d\n", b.b2.v);

  x -= (1 << 2) * b.b2.v;
  printf("2bit input: \t %u\n", x);
  b.b1.v = x / (1 << 1);
  printf("2nd bit: \t %d\n", b.b1.v);

  x -= (1 << 1) * b.b1.v;
  printf("1bit input: \t %u\n", x);
  b.b0.v = x;
  printf("1st bit: \t %d\n", b.b0.v);
  */
  return b;
}


unsigned int bits8_to_int(struct bits8 x);


void bits8_print(struct bits8 v);


struct bits8 bits8_add(struct bits8 x, struct bits8 y);


struct bits8 bits8_negate(struct bits8 x);


struct bits8 bits8_mul(struct bits8 x, struct bits8 y);
