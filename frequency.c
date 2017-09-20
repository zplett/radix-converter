//Zac Plett, September 16 2017 

#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define LENGTH 256

/*reads in characters and prints the amount of times each character was used, the percentage of 
  each character usage, and the maximum and minimum used characters
 */
int main() {
  
  int arr[LENGTH];
  memset(arr, 0, sizeof(arr));
  int x, i, j, k, l, z, minCount, total, maxCount, q, p;
  for(;;) {
    x = getchar();
    if (x == EOF) break;
    arr[x] += 1;
  }
  printf("\n");
  printf("char       Frequencies       Percentage\n");
  total = 0;
  maxCount = 0;
  char min[LENGTH], max[LENGTH];
  for (k = 0; k < 26; k++) {
    if (arr[k+'a'] > maxCount) { maxCount = arr[k+'a']; }
  }
  minCount = maxCount;
  for (l = 0; l < 26; l++) {
    if (arr[l+'a'] < minCount) { minCount = arr[l+'a']; }
  }
  for (z = 0; z < LENGTH; z++) {
    if (arr[z] == maxCount) { max[z] = z; }
    else if (arr[z] == minCount) { min[z] = z; }
  }
  for (j = 0; j < 26; j++) {
    total += arr[j+'a'];
  }
  for (i = 0; i < 26; i++) {
    printf("%c             %d              %f\n",i+'a', arr[i+'a'],(100*((1.0f*arr[i+'a'])/(1.0f*total))));
  }
  printf("maximum characters: ");
  for (p = 0; p < 26; p++) {
    if (max[p+'a'] > 0) { printf("%c ", p+'a'); }
  } printf("\n");
  printf("minimum characters: ");
  for (q = 0; q < 26; q++) {
    if (min[q+'a'] > 0) { printf("%c ", q+'a'); }
  } printf("\n");
}
