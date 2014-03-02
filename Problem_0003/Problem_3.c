/* Problem_3.c */
/* 2012-06-30 */

#include <stdio.h>
#include "../common-function/commfunc.h"

#define FACTOR 600851475143

int main(void)
{
  int ptemp = 0;
  unsigned long long max = 0;

  max = FACTOR;

  while(max != 1){
    ptemp = nextpnum(ptemp);
    if(max % ptemp == 0) 
      max /= ptemp;
  }

  printf("The largest prime factor : %d\n", ptemp);

  return 0;
}
