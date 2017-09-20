//Zac Plett, September 17 2017
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "bits.h"
#define MAX_VAL pow((double)2, (double)(CHAR_BIT-1))

//prints characters in their binary values
void print_bits(int i) {
  int index, x, arr[CHAR_BIT] = {0};
  for (index = 0; index < CHAR_BIT; index++) {
    if (i==1) {
      arr[CHAR_BIT-index-1] = 1;
      break;
    }
    else if (i%2 == 0) {
      arr[CHAR_BIT-index-1] = 0;
      i /= 2;
    }
    else {
      arr[CHAR_BIT-index-1] = 1;
      i /= 2;
    }
  }
  for (x = 0; x < CHAR_BIT; x++) {
    printf("%d",arr[x]);
  }  
}

//decodes binary numbers to their character values
//if invalid: print error and return
//if valid: ignore spaces and convert to ascii char
void decode_bits(int j) {
  static int arr[CHAR_BIT] = {0}, count = 0;
  int sum = 0;
  int power = MAX_VAL;
  if (isspace(j)) return;
  else if ((j-'0') == 1 || (j-'0') == 0) arr[count++] = j;
  else {
    memset(arr, 0, sizeof(arr));
    printf("Error, invalid input values!");
    return;
  }
  if (count == CHAR_BIT) {
    for (int i = 0; i < CHAR_BIT; i++) {
      if (arr[i] == '1') sum += power;
      power /= 2;
    }
    printf("%c", sum);
    count = 0;
  }
}