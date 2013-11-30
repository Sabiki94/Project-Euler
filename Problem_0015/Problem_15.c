/* Problem_15.c */
/* 2012-07-14 */
/* UNDONE */

#include <stdio.h>

int main(void)
{
  /* calcrate 40C20 */
  unsigned long long int i, nur = 0, deno = 0, temp = 20;

  for(i = 40; i >= 21; i--){
    nur *= i;
  }
  for(i = temp; i >= 1; i--)
    deno *= i;

  printf("%llu / %llu\n", nur, deno);
  printf("number of routes : %llu\n", nur / deno);

  return 0;
}
