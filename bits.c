//Zac Plett, September 17 2017
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "bits.h"
#include "getnum.h"

#define ARRAYSIZE (10)

//prints characters in their binary values
void print_bits(long i) {
  deconstructBinary(i);
  printf("\n");
}

//validates whether a given input is a valid input for the base
int validate(int c, int base) {
  if (base == 2) if (c - '0' == 1 || c - '0' == 0) return 1;
  if (base == 8) if ((c - '0' >= 0) && (c - '0' <= 7)) return 1;
  if (base == 10) if (c - '0' >= 0 && c - '0' <= 9) return 1;
  if (base == 16)  if ((c - '0' >= 0 && c - '0' <= 9) || (c >= 'a' && c <= 'f')) return 1; 
  return 0;
}

//converts to a long
long combine(const int *base, int (*arr)[], const int *size) {
  long co = 0, sum = 0, power = pow((double)(*base), (double)(*size-1));
  for (int i = 0; i < *size; i++) {
    if (*base == 16) co = ((*arr)[i] - '0' > 9) ? ((*arr)[i] - 'a') + 10 : (*arr)[i] - '0';
    else co = (*arr)[i] - '0';
    sum += co*power;
    power /= *base;
  }
  return sum;
}

//decodes binary numbers to their character values
//if invalid: print error and return
//if valid: ignore spaces and convert to ascii char
void decode_bits(int j, int base) {
  static int arr[ARRAYSIZE] = {0}, count = 0;
  int size = ARRAYSIZE;
  if (isspace(j)) return;
  else if ((validate(j, base)) == 1 ) arr[count++] = j;
  else {
    memset(arr, 0, sizeof(arr));
    printf("Error, invalid input values!");
    return;
  }
  if (count == ARRAYSIZE) {
    long sum = combine(&base, &arr, &size);
    printf("%c", (int) sum);
    count = 0;
  }
}
