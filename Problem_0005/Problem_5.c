/* Problem_5.c */
/* 2012-06-30  */
/* 2012-07-11  */

#include <stdio.h>

int main(void)
{
	int i, j, count = 0;

	i = 1, j = 1;
	while(j != 20){
		count++;
		if(i % j){
			i++;
			j = 1;
			continue;
		}
		j++;
	}

	printf("count = %d\n\n", count);
	printf("%d\n", i);

	return 0;
}
