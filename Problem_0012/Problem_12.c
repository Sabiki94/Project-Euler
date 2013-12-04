/* Problem_12.c */
/* 2012-07-13 */

#include <stdio.h>

#define GOAL 500

int main(void){
  int i, t_num = 0, divisor_count = 0, tt = 0, maxtemp = 0;

  while (divisor_count < GOAL){
      tt++; // Triangle num temp
      t_num += tt;

      divisor_count = 0;
      maxtemp = t_num;
      for (i = 1; i < maxtemp; i++)
      if (t_num % i == 0){
          divisor_count += 2;
          maxtemp = t_num / i;
      }
  }

  printf("t_num : %d\n", t_num);

  return 0;
}
