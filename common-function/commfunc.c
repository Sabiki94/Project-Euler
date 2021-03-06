#include <math.h>
#include "commfunc.h"

uint64_t nextpnum(uint64_t num)
{
    uint64_t count = 2;

    // 2以外の素数は奇数なので奇数なら+2、偶数なら++
    if (num % 2)	num += 2;
    else num++;

    // numは奇数にしているので2から割っていくのは無意味
    for (count = 3; count <= (int)sqrt((double)num); count += 2)
    {
        if (num % count == 0)
        {
            num += 2;
            count = 1;
            continue;
        }
    }
    if (num == 1) num++;    // 1は素数ではない

    return num;
}
