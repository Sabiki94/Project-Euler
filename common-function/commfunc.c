#include <math.h>
#include "commfunc.h"

uint64_t nextpnum(uint64_t num)
{
    uint64_t count = 2;

    // 2�ȊO�̑f���͊�Ȃ̂Ŋ�Ȃ�+2�A�����Ȃ�++
    if (num % 2)	num += 2;
    else num++;

    // num�͊�ɂ��Ă���̂�2���犄���Ă����͖̂��Ӗ�
    for (count = 3; count <= (int)sqrt((double)num); count += 2)
    {
        if (num % count == 0)
        {
            num += 2;
            count = 1;
            continue;
        }
    }
    if (num == 1) num++;    // 1�͑f���ł͂Ȃ�

    return num;
}
