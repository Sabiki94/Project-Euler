#include <math.h>
#include "commfunc.h"

uint64_t nextpnum(uint64_t num)
{
    uint64_t count = 2;

    // 2ˆÈŠO‚Ì‘f”‚ÍŠï”‚È‚Ì‚ÅŠï”‚È‚ç+2A‹ô”‚È‚ç++
    if (num % 2)	num += 2;
    else num++;

    // num‚ÍŠï”‚É‚µ‚Ä‚¢‚é‚Ì‚Å2‚©‚çŠ„‚Á‚Ä‚¢‚­‚Ì‚Í–³ˆÓ–¡
    for (count = 3; count <= (int)sqrt((double)num); count += 2)
    {
        if (num % count == 0)
        {
            num += 2;
            count = 1;
            continue;
        }
    }
    if (num == 1) num++;    // 1‚Í‘f”‚Å‚Í‚È‚¢

    return num;
}
