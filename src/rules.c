#include "rules.h"

bool cell_alive(bool alive_now, int neighbors)
{
    if (alive_now)
        return neighbors > 1 && neighbors < 4;
    else 
        return neighbors == 3;
}

