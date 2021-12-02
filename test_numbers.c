#include <stdio.h>
#include <stdlib.h>
#include "numbers.h"

int main() {
  struct bits8 test = bits8_from_int(131);
  bits8_print(test);
  int test2 = bits8_to_int(test);
  printf("%d\n", test2);
  struct bits8 test3 = bits8_add(test, test);
  printf("Add result: %d = ", bits8_to_int(test3)); bits8_print(test3);
  struct bits8 test4 = bits8_negate(test);
  bits8_print(test4);
  printf("2's comp: %d negates to: %d\n", bits8_to_2(test), bits8_to_2(test4));
  printf("Multiply: ...\n");
  struct bits8 test5 = bits8_mul(bits8_from_int(20), bits8_from_int(20));
  printf("Multiply result: %d = ", bits8_to_int(test5)); bits8_print(test5);
}
