/* Problem_10.c */
/* 2012-07-13 */
/* 2012-11-07 */

#include <stdio.h>
#include <Windows.h>
#include <math.h>

#define NUM 2000000

UINT64 nextpnum(UINT64 num)
{
  UINT64 count = 2;

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
  UINT64 sum = 0, ptemp = 0;

  while(ptemp <= NUM){
    sum += ptemp;
    ptemp = nextpnum(ptemp);
	printf("%.2f%%\n", (ptemp * 100.0) / NUM);
  }

  printf("The sum of all the primes below 2000000 : %llu\n", sum);

  return 0;
}
