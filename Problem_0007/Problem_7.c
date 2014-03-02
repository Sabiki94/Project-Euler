/* Problem_7.c */
/* 2012-07-11  */

#include <stdio.h>
#include "../common-function/commfunc.h"

int main(void)
{
    int pnum = 0, count = 1, pcount = 1;

    for (pcount = 1; pcount <= 10001; pcount++)
        pnum = nextpnum(pnum);

    printf("10001th Prime number : %d\n", pnum);

    return 0;
}
