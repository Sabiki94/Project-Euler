/* main.c */
/* 2013-01-14 */
/* DONE */

#include <stdio.h>

#define NUM 1001
#if NUM % 2 == 0
#error
#endif

int main(void)
{
    int x, y;
    int i, lim = NUM - 1;
    int sum = NUM * NUM;

    i = NUM * NUM;
    y = 0;
    x = NUM - 1;

    while(1 < i)
    {
        while(NUM - lim - 1 < x)
        {
            i--;
            if(y == --x || x == (NUM - 1) - y) sum += i;
        }
        while(y < lim)
        {
            i--;
            if(++y == x || x == (NUM - 1) - y) sum += i;
        }
        while(x < lim)
        {
            i--;
            if(y == ++x || x == (NUM - 1) - y) sum += i;
        }
        while(NUM - lim  < y)
        {
            i--;
            if(--y == x || x == (NUM - 1) - y) sum += i;
        }
        lim--;
    }

    printf("The sum of the numbers of on the diagonals is %d\n", sum);

    return 0;
}
