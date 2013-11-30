/* Problem_6.c */
/* 2012-07-11  */

#include <stdio.h>

int main(void)
{
	int i = 1, diff;
	int l = 0, r = 0;

	for(i = 1; i <= 100; i++){
		l += i * i;
		r += i;
	}
	r *= r;
	diff = r - l;

	printf("l = %d\n", l);
	printf("r = %d\n", r);
	printf("diff = %d\n", diff);

	return 0;
}
