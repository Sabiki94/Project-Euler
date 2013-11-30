/* Problem_7.c */
/* 2012-07-11  */

#include <stdio.h>

int nextpnum(int num)
{
	int count;

	if(num % 2) num += 2;
	else num++;
	for(count = 3;count * count <= num;count+=2){
		if(num % count == 0){
			if(num % 2) num += 2;
			else num++;
			count = 1;
		}
	}
	if(num == 1) num++;

	return num;
}

int main(void)
{
	int pnum = 0, count = 1, pcount = 1;

	for(pcount = 1; pcount <= 10001; pcount++)
		pnum = nextpnum(pnum);

	printf("10001th Prime number : %d\n", pnum);

	return 0;
}
