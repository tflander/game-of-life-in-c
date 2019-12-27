#include "grid.h"
#include "rules.h"
#include "neighbor_counter.h"
#include "render.h"
#include <string.h>
#include <stdlib.h> 
#include <stdio.h> 
#include <time.h>

int randomNumberBoundry = RAND_MAX / 2;

void randomizeGrid(struct Grid grid, int seed) {
    srand(seed);
    for ( int r = 0; r < grid.numRows; r++ ) {
        for (int c = 0; c < grid.numCols; ++c) {
            struct Point point = {.x=c, .y=r};
            bool isLive = rand() > randomNumberBoundry;
            setCell(grid, point, isLive);
        }
    }    
}

void tick(struct Grid grid) {

    // struct Grid updatedGrid = createEmptyGrid(grid->numRows, grid->numCols);
    // for(int c = 0; c < grid->numCols; ++c) {
    //     for(int r = 0; r < grid->numRows; ++r) {
    //         struct Point point = {.x=c, .y=r};
    //         int neighborCount = count_neighbors(*grid, point);
    //         bool aliveNow = isAlive(*grid, point);
    //         setCell(updatedGrid, point, cell_alive(aliveNow, neighborCount));
    //     }
    // }
    // destroyGrid(*grid);
    // grid->data = updatedGrid.data;

    char gridBufferForUpdate[grid.numCols][grid.numRows];
    struct Grid updatedGrid = {gridBufferForUpdate, grid.numCols, grid.numRows};
    for(int c = 0; c < grid.numCols; ++c) {
        for(int r = 0; r < grid.numRows; ++r) {
            struct Point point = {.x=c, .y=r};
            int neighborCount = count_neighbors(grid, point);
            bool aliveNow = isAlive(grid, point);
            setCell(updatedGrid, point, cell_alive(aliveNow, neighborCount));
        }
    }
    memcpy(grid.data, &updatedGrid, sizeof(char) * grid.numRows * grid.numRows);

}

