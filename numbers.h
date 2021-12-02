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
  return b;
}


unsigned int bits8_to_int(struct bits8 x) {
  unsigned int i = x.b0.v;
  i += x.b1.v * (1 << 1);
  i += x.b2.v * (1 << 2);
  i += x.b3.v * (1 << 3);
  i += x.b4.v * (1 << 4);
  i += x.b5.v * (1 << 5);
  i += x.b6.v * (1 << 6);
  i += x.b7.v * (1 << 7);
  return i;
}


void bits8_print(struct bits8 v) {
  printf("%d%d%d%d%d%d%d%d\n", v.b7.v, v.b6.v, v.b5.v, v.b4.v, v.b3.v, v.b2.v, v.b1.v, v.b0.v);
}


struct bits8 bits8_add(struct bits8 x, struct bits8 y) {
  struct bits8 sum;
  bool c = false;
  sum.b0.v = x.b0.v ^ y.b0.v ^ c;
  c = (x.b0.v && y.b0.v) || ((x.b0.v || y.b0.v) && c);
  sum.b1.v = x.b1.v ^ y.b1.v ^ c;
  c = (x.b1.v && y.b1.v) || ((x.b1.v || y.b1.v) && c);
  sum.b2.v = x.b2.v ^ y.b2.v ^ c;
  c = (x.b2.v && y.b2.v) || ((x.b2.v || y.b2.v) && c);
  sum.b3.v = x.b3.v ^ y.b3.v ^ c;
  c = (x.b3.v && y.b3.v) || ((x.b3.v || y.b3.v) && c);
  sum.b4.v = x.b4.v ^ y.b4.v ^ c;
  c = (x.b4.v && y.b4.v) || ((x.b4.v || y.b4.v) && c);
  sum.b5.v = x.b5.v ^ y.b5.v ^ c;
  c = (x.b5.v && y.b5.v) || ((x.b5.v || y.b5.v) && c);
  sum.b6.v = x.b6.v ^ y.b6.v ^ c;
  c = (x.b6.v && y.b6.v) || ((x.b6.v || y.b6.v) && c);
  sum.b7.v = x.b7.v ^ y.b7.v ^ c;
  c = (x.b7.v && y.b7.v) || ((x.b7.v || y.b7.v) && c);
  return sum;
}


struct bits8 bits8_negate(struct bits8 x) {
  x.b0.v = !x.b0.v;
  x.b1.v = !x.b1.v;
  x.b2.v = !x.b2.v;
  x.b3.v = !x.b3.v;
  x.b4.v = !x.b4.v;
  x.b5.v = !x.b5.v;
  x.b6.v = !x.b6.v;
  x.b7.v = !x.b7.v;
  return bits8_add(x, bits8_from_int(1));
}

int bits8_to_2(struct bits8 x) {
  int i = x.b0.v;
  i += x.b1.v * (1 << 1);
  i += x.b2.v * (1 << 2);
  i += x.b3.v * (1 << 3);
  i += x.b4.v * (1 << 4);
  i += x.b5.v * (1 << 5);
  i += x.b6.v * (1 << 6);
  i -= x.b7.v * (1 << 7);
  return i;
}

struct bits8 bits8_mul(struct bits8 x, struct bits8 y) {
  struct bits8 z;
  z.b0.v = x.b0.v & y.b0.v;
  z.b1.v = x.b0.v & y.b1.v;
  z.b2.v = x.b0.v & y.b2.v;
  z.b3.v = x.b0.v & y.b3.v;
  z.b4.v = x.b0.v & y.b4.v;
  z.b5.v = x.b0.v & y.b5.v;
  z.b6.v = x.b0.v & y.b6.v;
  z.b7.v = x.b0.v & y.b7.v;
  printf("x = %d = ", bits8_to_int(x)); bits8_print(x);
  printf("y = %d = ", bits8_to_int(y)); bits8_print(y);
  printf("calculating x*y = %d = ", bits8_to_int(z)); bits8_print(z);
  struct bits8 z1;
  z1.b0.v = false;
  z1.b1.v = x.b1.v & y.b0.v;
  z1.b2.v = x.b1.v & y.b1.v;
  z1.b3.v = x.b1.v & y.b2.v;
  z1.b4.v = x.b1.v & y.b3.v;
  z1.b5.v = x.b1.v & y.b4.v;
  z1.b6.v = x.b1.v & y.b5.v;
  z1.b7.v = x.b1.v & y.b6.v;
  z = bits8_add(z, z1);
  printf("calculating x*y = %d = ", bits8_to_int(z)); bits8_print(z);
  z1.b1.v = false;
  z1.b2.v = x.b2.v & y.b0.v;
  z1.b3.v = x.b2.v & y.b1.v;
  z1.b4.v = x.b2.v & y.b2.v;
  z1.b5.v = x.b2.v & y.b3.v;
  z1.b6.v = x.b2.v & y.b4.v;
  z1.b7.v = x.b2.v & y.b5.v;
  z = bits8_add(z, z1);
  printf("calculating x*y = %d = ", bits8_to_int(z)); bits8_print(z);
  z1.b2.v = false;
  z1.b3.v = x.b3.v & y.b0.v;
  z1.b4.v = x.b3.v & y.b1.v;
  z1.b5.v = x.b3.v & y.b2.v;
  z1.b6.v = x.b3.v & y.b3.v;
  z1.b7.v = x.b3.v & y.b4.v;
  z = bits8_add(z, z1);
  printf("calculating x*y = %d = ", bits8_to_int(z)); bits8_print(z);
  z1.b3.v = false;
  z1.b4.v = x.b4.v & y.b0.v;
  z1.b5.v = x.b4.v & y.b1.v;
  z1.b6.v = x.b4.v & y.b2.v;
  z1.b7.v = x.b4.v & y.b3.v;
  z = bits8_add(z, z1);
  printf("calculating x*y = %d = ", bits8_to_int(z)); bits8_print(z);
  z1.b4.v = false;
  z1.b5.v = x.b5.v & y.b0.v;
  z1.b6.v = x.b5.v & y.b1.v;
  z1.b7.v = x.b5.v & y.b2.v;
  z = bits8_add(z, z1);
  printf("calculating x*y = %d = ", bits8_to_int(z)); bits8_print(z);
  z1.b5.v = false;
  z1.b6.v = x.b6.v & y.b0.v;
  z1.b7.v = x.b6.v & y.b1.v;
  z = bits8_add(z, z1);
  printf("calculating x*y = %d = ", bits8_to_int(z)); bits8_print(z);
  z1.b6.v = false;
  z1.b7.v = x.b7.v & y.b0.v;
  z = bits8_add(z, z1);
  printf("calculating x*y = %d = ", bits8_to_int(z)); bits8_print(z);
  return z;
}
