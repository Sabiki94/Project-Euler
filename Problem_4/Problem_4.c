/* Problem_4.c */
/* 2012-06-30 */

#include <stdio.h>
#include <math.h>
#define CALC_DIGIT 999

int invnum(double num)
{
  double inv = 0.0, dig = 0.0, count = 1.0;

  dig = (int)log10(num);

  inv += ((int)num % 10) * pow(10.0,dig);
  for(count = 1;count <= dig;count++){
    num /= 10;
    inv += ((int)num % 10) * pow(10.0,dig-count);
  }

  return (int)inv;
}

int main(void)
{
  int product = 0, count = 0, num = 0;

  num = CALC_DIGIT;
  count = num;
  for(;;){
    product = num * count;
    if(product == invnum(product)){
      printf("%d * %d = %d!\n", num, count, invnum(product));
      break;
    }
    count--;
    if( count == CALC_DIGIT - ((int)pow(10.0,log10((double)CALC_DIGIT)-1)) ){
      num--;
      count = CALC_DIGIT;
    }
  }

  return 0;
}
