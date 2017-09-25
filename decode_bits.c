//Zac Plett, September 17 2017

#include <string.h>
#include <stdio.h>
#include "bits.h"
#include "getnum.h"

//calls decode_bits to decode the binary values entered by the user
int main(int argc, char *argv[]) {
  if (argc == 1) todecimal();
  else if (argc > 1) {
    if (strcmp(argv[1], "-b") == 0) tobinary();
    else if (strcmp(argv[1], "-o")==0) tooctal();
    else if (strcmp(argv[1], "-h")==0) tohex();
  }
  else printf("Flag invalid");
}
