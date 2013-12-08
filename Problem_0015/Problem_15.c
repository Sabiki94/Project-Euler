/* Problem_15.c */
/* 2012-07-14 */
/* 2013-12-08 */

/* Calculate 40 C 20 */
/* Using below mathematical property :  */
/* (nC0)^2 + (nC1)^2 + ... + (nCn)^2 == 2nCn  */

#include <stdio.h>
#include <stdint.h>

#define N 40
#define M 20

int combination(int n, int m)
{
    int i;
    uint64_t nur, deno;

    nur = 1;
    for (i = n; i >= n-m+1; i--) {
        nur *= i;
    }

    deno = 1;
    for (i = 1; i <= m; i++) {
        deno *= i;
    }

    return (int)(nur/deno);
}

int main(void)
{
    int i;
    uint64_t result;

    result = 0;
    for (i = 0; i <= M; i++) {
        result += (uint64_t)combination(M, i) * (uint64_t)combination(M, i);
    }

  printf("number of routes : %llu\n", result);

  return 0;
}
