#include <stdlib.h>
#include "numbers.h"

int main() {
  struct bits8 test = bits8_from_int(460);
  printf("result: %d%d%d%d%d%d%d%d\n", test.b7.v, test.b6.v, test.b5.v, test.b4.v, test.b3.v, test.b2.v, test.b1.v, test.b0.v);
}
