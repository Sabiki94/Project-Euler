/* Problem_10.c */
/* 2012-07-13 */
/* 2012-11-07 */
/* 2013-12-05 */

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "../common-function/commfunc.h"

#define NUM 2000000

int main(void)
{
  uint64_t sum = 0, ptemp = 0;

  printf("Calculating...\n");
  while (ptemp <= NUM){
      putchar('\r');
      sum += ptemp;
      ptemp = nextpnum(ptemp);
      printf("%.2f%%\r", (ptemp * 100.0) / NUM);
  }
  printf("done.  \n");

  printf("The sum of all the primes below 2000000 : %llu\n", sum);

  return 0;
}
