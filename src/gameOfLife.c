#include "grid.h"
#include "rules.h"
#include "neighbor_counter.h"
#include <string.h>

void tick(struct Grid grid) {
    char updatedGrid[grid.numCols][grid.numRows];
    for(int c = 0; c < grid.numCols; ++c) {
        for(int r = 0; r < grid.numRows; ++r) {
            struct Point point = {.x=c, .y=r};
            int neighborCount = count_neighbors(grid, point);
            bool aliveNow = isAlive(grid, point);
            if(cell_alive(aliveNow, neighborCount)) {
                updatedGrid[c][r] = 'X';
            } else {
                updatedGrid[c][r] = ' ';
            }
        }
    }
    memcpy(grid.data, &updatedGrid, sizeof(char) * grid.numRows * grid.numRows);
}
