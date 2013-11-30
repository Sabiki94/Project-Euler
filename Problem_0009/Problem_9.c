/* Problem_9.c */
/* 2012-07-14 */
/* 2012-11-07 */

#include <stdio.h>

int mysqrt(int num)
{
	int i;

	for(i = num / 2; i > 0; i--)
		if(i * i == num) return i;

	return 0;
}

int main(void)
{
  int a, b, c;
  
	  for(a = 0; a <= 500; a++)
		  for(b = 0; b <= 500; b++) {
			  c = mysqrt(a * a + b * b);
			  if(!(a < b && b < c)) continue;
			  if(a + b + c == 1000) {
				  printf("%d * %d * %d = %d\n", a, b, c, a*b*c);
			  }
		  }

  return 0;
}
