#include "grid.h"
#include "rules.h"
#include "neighbor_counter.h"
#include "render.h"
#include <string.h>
#include <stdlib.h> 
#include <stdio.h> 
#include <time.h>

void tick(struct Grid grid) {

    char gridBufferForUpdate[grid.numCols][grid.numRows];
    struct Grid updatedGrid = {(char*)gridBufferForUpdate, .numCols=grid.numCols, .numRows=grid.numRows};
    for(int c = 0; c < grid.numCols; ++c) {
        for(int r = 0; r < grid.numRows; ++r) {
            struct Point point = {.x=c, .y=r};
            int neighborCount = count_neighbors(grid, point);
            bool aliveNow = isAlive(grid, point);
            setCell(updatedGrid, point, cell_alive(aliveNow, neighborCount));
        }
    }
    memcpy(grid.data, &gridBufferForUpdate, sizeof(char) * grid.numRows * grid.numCols);
}

