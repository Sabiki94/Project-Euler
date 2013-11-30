/* Problem_347.c */
/* 2012-11-07 */
/* UNDONE */

#include <stdio.h>
#include <Windows.h>

INT64 M(INT64 p, INT64 q, int N);
INT64 S(int N);
INT64 mypow(INT64 base, INT64 exponent);
int nextpnum(int num);

int main(void)
{
	const int N = 10000000;
	int p = 3, q = 5;

	printf("M(%d, %d, %d) = %lld\n", p, q, N, M(p,q,N));
	printf("S(%d) = %lld\n", N, S(N));

	return 0;
}

INT64 M(INT64 p, INT64 q, int N)
{
	int i, j;
	INT64 temp, max;

	i = j = 1;
	temp = 1;
	max = 0;

	if(p * q > N)
		return 0;

	while(mypow(p, i) <= N)
	{
		if(mypow(q, j) > N)
		{
			j = 1;
			i++;
			continue;
		}

		temp = 1;
		temp *= mypow(p, i);
		temp *= mypow(q, j);

		if(max < temp && temp <= N) max = temp;
		j++;
	}

	return max;
}

INT64 S(int N)
{
	int p, q, pmq, q_lim;
	INT64 sum, tmp;

	pmq = 0;
	q_lim = N;
	p = 2;
	q = 3;
	sum = 0;
	while (p < N && q <N)
	{
		tmp = M(p, q, N);
		sum += tmp;
		if(tmp)
		{
			//printf("p = %d, q = %d, %lld  sum = %lld\n", p,q,tmp, sum);
			pmq = q;
		}
		q = nextpnum(q);
		if(q > q_lim)
		{
			p = nextpnum(p);
			q = nextpnum(p);
			q_lim = pmq;
		}
	}

	return sum;
}

INT64 mypow(INT64 base, INT64 exponent)
{
	int i;
	INT64 temp;

	if(exponent == 0)	return 1;

	temp = 1;
	for(i = 0; i < exponent; i++)
		temp *= base;

	return temp;
}

int nextpnum(int num)
{
	int count;

	// Šï”‚È‚çŽŸ‚Ì‘f”‚Í•K‚¸Šï”‚È‚Ì‚Å+2A‚»‚¤‚Å‚È‚¯‚ê‚Î++
	if(num % 2) num += 2;
	else num++;

	for(count = 3;count * count <= num;count+=2){
		if(num % count == 0){
			num += 2;
			count = 3 - 2;
		}
	}
	if(num == 1) num++;	// 1‚Í‘f”‚Å‚Í‚È‚¢

	return num;
}
