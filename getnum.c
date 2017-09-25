//zac plett september 20 2017
#include "bits.h"
#include "getnum.h"
#include <stdint.h>
#include <ctype.h>
#include <stdio.h>
#include <limits.h>

#define ARRAYSIZE 10

long deconstructBinary(long);
static long makeBinary(const int);
static void skipSpace(void);
static uint8_t validate_base(const int *, const int *);
static void rearrange(int (*)[], const int *); 
static long getnum(void);
void tobinary(void);
void todecimal(void);
void tooctal(void);
void tohex(void);
void getnumWrap(const uint8_t);
long flushBuffer(int (*)[], const int *, const int *, const int *, const int *, int *);

//continually calls getnum to take in multiple inputs
void getnumWrap(const uint8_t base) {
  for(;;) {
    long block = getnum();
    if (block == -1) break;
    if (block == -2) continue;
    if (base == 10) printf("%ld\n", block);
    else if (base == 8) printf("0%lo\n", block);
    else if (base == 16) printf("0x%lx\n", block);
    else if (base == 2) { printf ("0b"); print_bits(block); }
    else { printf("Error, invalid base.\n"); break; }
  }
}

//Reads in numbers from the user to be converted
static long getnum(void) {
  int ch, negative = 1, size = ARRAYSIZE, index = 0, count = 0, base = -1, arr[ARRAYSIZE] = {0};
  uint8_t valid;
  long buffer;
  for(;;) {
    ch = getchar();
    if (isalpha(ch)) ch = tolower(ch);
    if (count == 0 && ch == EOF) return -1;
    if (isspace(ch)) {
      if (count == 0) continue;
      else if (count > 0) {
	if (base != 2) return flushBuffer(&arr, &size, &index, &base, &negative, &count);
	else if (base == 2) {
	  makeBinary(-1);
	  if (negative == -1) printf("-");
	  return buffer;
	}
      }
    }
    if (ch == '-' && count == 0) { negative = -1; continue; }
    if (base == -1) {
      valid = validate_base(&ch, &count);
      count++;
      switch (valid) {
      case 0: continue;
      case 255:
	printf("ERROR\n");
	skipSpace();
	return -2; 
      case 2: case 8: case 10: case 16:
	base = valid;
       	continue;
      }
    }
    else
      if (ch == EOF) {
	if (base == 2) {
	  if (negative == -1) printf("-");
	  return buffer;
	}
	else return flushBuffer(&arr, &size, &index, &base, &negative, &count);
      }
      else if (validate(ch, base) == 1) {
	if (base == 2) buffer = makeBinary(ch);
	else if (base != 2) arr[index++] = ch;
	continue;
      }
      else {
	printf("ERROR\n");
	skipSpace();
	return -2;
      } 
   }
}

//skips to next white space
void skipSpace() {
  for (;;) {
    int x = getchar();
    if (isspace(x)) return;
  }
}

//returns binary digit using bitwise operations 
static long makeBinary(const int ch) {
  static long buffer = 0;
  if (ch == -1) { buffer = 0; return 0; }
  if (ch == '1') { buffer = buffer << 1; buffer = buffer | 1; }
  else if (ch == '0') buffer = buffer << 1;
  return buffer;
}

//constructs a binary value
long deconstructBinary(long dec) {
  long n = 1;
  n = n << (((sizeof(long))*4)-1);

  for (int i = 0; i < (int) (sizeof(long)*4); i++) {
    if ((n & dec) != 0) printf ("1");
    else if ((n & dec) == 0) printf ("0");
    n = n >> 1;
  }
  return n;
}

//determines the base given the entered prefix
uint8_t validate_base(const int *ch, const int *count) {
  if (*ch == '0') return *count == 0 ? 0 : 8;
  else if (isalpha(*ch)) {
    if (*count == 1) return *ch == 'x' ? 16 :
		       *ch == 'b' ? 2 : -1;
  }
  else if(isdigit(*ch)) {
    if (*ch - '0' > 0 && *count == 0) {
      ungetc(*ch, stdin);
      return 10;
    }
    else if (count != 0) {
      ungetc(*ch, stdin);
      return 8;
    }
  }
  return -1; 
}

//rearranges the array to correctly represent the value entered by the user
void rearrange(int (*arr)[], const int *numchar) {
  for (int j = ARRAYSIZE-1; j > -1; j--) {
    if (j < ARRAYSIZE - *numchar) (*arr)[j] = '0';
    else (*arr)[j] = (*arr)[j-(ARRAYSIZE-*numchar)];
  }
}

//flushes the current buffer
long flushBuffer(int (*arr)[], const int *size, const int *index, const int *base, const int *negative, int *count) {
  rearrange(arr, index);
  *count = 0;
  if (*negative == -1) printf("-");
  return (long) (combine(base, arr, size));
}

//converts to binary
void tobinary() {
  getnumWrap(2);
}

//converts to decimal
void todecimal() {
  getnumWrap(10);
}

//converts to octal
void tooctal() {
  getnumWrap(8);
}


//converts to hex
void tohex() {
  getnumWrap(16);
}
