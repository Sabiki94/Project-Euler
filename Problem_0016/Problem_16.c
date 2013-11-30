/* Problem_16.c */
/* 2012-07-14 */
/* UNDONE */

#include <stdio.h>
#include <math.h>
#include <Windows.h>

UINT64 mypow(int base, int exponent)
{
	int i;
	UINT64 temp;

	temp = 1;
	for(i = 0; i < exponent; i++)
		temp *= base;

	return temp;
}

int main(void)
{
	int ppow = 63, sum;
	long double temp;

	temp = pow((long double)2, 1000);

	printf("2^%d = %lf\n", ppow, temp);

	sum = 0;
	while(temp){
		sum += (int)temp % 10;
		temp /= 10;
	}

	printf("The sum of the digits of the number 2^%d : %d\n", ppow , sum);

	return 0;
}
