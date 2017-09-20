//Zac Plett, September 17 2017

#include <stdio.h>
#include "bits.h"
#include <ctype.h>
#include <limits.h>

//calls print_bits for characters entered by the user
int main() {
  int i;
  for (;;) {
    i = getchar();
    if (i == EOF) break;
    print_bits(i);
  } printf("\n");
}
