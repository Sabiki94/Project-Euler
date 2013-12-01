/* Problem_14.c */
/* 2012-07-14 */

#define LIMIT 1000000

#include <stdio.h>

int main(void)
{
    int count = 0, i, max = 0, max_n;
    long long int n;

    printf("*** Collatz Problem ***\n");

    for (i = LIMIT; 1 < i; i--){
        count = 0;
        n = i;
        while (n != 1){
            if (n % 2){
                n *= 3;
                n++;
            }
            else n /= 2;
            count++;
        }
        if (max < count){
            max = count;
            max_n = i;
        }
    }

    printf("longest : start from %d, count = %d\n", max_n, max);

    return 0;
}
