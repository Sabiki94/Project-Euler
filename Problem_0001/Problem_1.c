/* Problem_1.c */
/* 2012-06-30 */

#define BELOW_NUM 1000
#include <stdio.h>

int main(void)
{
    int sum = 0, count = 0;

    for (count = 0; count < BELOW_NUM; count++){
        if (count % 3 == 0 || count % 5 == 0)
            sum += count;
    }

    printf("Sum of all the multiples of 3 or 5 below %d : %d\n", BELOW_NUM, sum);

    return 0;
}
