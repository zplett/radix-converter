//Zac Plett, September 17 2017

#include <stdio.h>
#include "bits.h"

//calls decode_bits to decode the binary values entered by the user
int main() {
  int j;
  for (;;) {
    j = getchar();
    if (j == EOF) break;
    decode_bits(j);
  }
}
