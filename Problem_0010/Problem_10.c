/* Problem_10.c */
/* 2012-07-13 */
/* 2012-11-07 */
/* 2013-12-05 */

#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define NUM 2000000

uint64_t nextpnum(uint64_t num)
{
  uint64_t count = 2;

  if(num % 2)	num+=2;
  else num++;
  for(count = 3;count <= (int)sqrt((long double)num);count+=2){
    if(num % count == 0){
      num += 2;
      count = 1;
	  continue;
    }
  }
  if(num == 1) num++;

  return num;
}

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
