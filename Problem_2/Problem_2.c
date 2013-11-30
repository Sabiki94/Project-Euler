/* Sum of the even-valued terms of Fibonacci sequence */
/* Problem_2.c */
/* 2012-06-30 */

/* fib_l, fib_r         */
/*  ----                */
/* |1, 2|, 3, 5, 8, ... */
/*  ----                */
/*     ----             */
/* 1, |2, 3|, 5, 8, ... */
/*     ----             */

#include <stdio.h>

int main(void)
{
	int sum = 0, fib_l = 1, fib_r = 2;

	/*
	while(1) {
	if(fib_l % 2 == 0)
	sum += fib_l;
	fib_r += fib_l;
	fib_l = fib_r - fib_l;
	if(fib_l > 4000000) break;
	} */
	while(4000000 > fib_l) {
		if(fib_l % 2 == 0)
			sum += fib_l;
		fib_r += fib_l;
		fib_l = fib_r - fib_l;
	}

	puts("*** The sum of the even-valued the Fbonacci sequence whose values do not exceed four million ***");
	printf("Result:%d\n", sum);

	return 0;
}
