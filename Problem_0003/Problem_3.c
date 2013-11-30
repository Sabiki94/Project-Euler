/* Problem_3.c */
/* 2012-06-30 */

#include <stdio.h>

#define FACTOR 600851475143

int nextpnum(int num);

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

int nextpnum(int num)
{
  int count = 2;

  num++;
  for(count = 2;count <= num / 2;count++){
    if(num % count == 0){
      num++;
      count=2;
    }
  }
  if(num == 1) num++;

  return num;
}
