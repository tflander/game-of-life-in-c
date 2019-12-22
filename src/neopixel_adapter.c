#include "neopixel_adapter.h"
#include <stdio.h>

int strandOffsetForPoint(struct Grid gridForAdapter, struct Point gridPoint) {

    bool isEvenRow = (gridPoint.y % 2) == 0;

    int offset = gridPoint.x;
    if(!isEvenRow) {
        offset = gridForAdapter.numCols - offset - 1;
    }

    return offset + (gridPoint.y * gridForAdapter.numCols);
}
