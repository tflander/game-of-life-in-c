#include "grid.h"
#include "rules.h"
#include "neighbor_counter.h"
#include "render.h"
#include <string.h>
#include <stdlib.h> 
#include <stdio.h> 
#include <time.h>

struct Grid createEmptyGrid(int numRows, int numColumns) {

    char **grid = (char**) malloc(numRows * sizeof(char*));
    for ( int r = 0; r < numRows; r++ ) {
        grid[r] = (char*) malloc(numColumns * sizeof(char));

        for (int c = 0; c < numColumns; ++c) {
            grid[r][c] = ' ';
        }
    }

    struct Grid gridResult = {grid, numRows, numColumns};
    return gridResult;

}

struct Grid createRandomGrid(int numRows, int numColumns, int seed) {
    srand(seed);
    struct Grid grid = createEmptyGrid(numRows, numColumns);
    int randomNumberBoundry = RAND_MAX / 2;
    for ( int r = 0; r < numRows; r++ ) {
        for (int c = 0; c < numColumns; ++c) {
            struct Point point = {.x=c, .y=r};
            bool isLive = rand() > randomNumberBoundry;
            setCell(grid, point, isLive);
        }
    }
    return grid;
}

void destroyGrid(struct Grid grid) {
   for ( int i = 0; i < grid.numRows; i++ )
    {
        free(grid.data[i]);
    }

    free(grid.data);    
}

void tick(struct Grid* grid) {

    struct Grid updatedGrid = createEmptyGrid(grid->numRows, grid->numCols);
    for(int c = 0; c < grid->numCols; ++c) {
        for(int r = 0; r < grid->numRows; ++r) {
            struct Point point = {.x=c, .y=r};
            int neighborCount = count_neighbors(*grid, point);
            bool aliveNow = isAlive(*grid, point);
            setCell(updatedGrid, point, cell_alive(aliveNow, neighborCount));
        }
    }
    destroyGrid(*grid);
    grid->data = updatedGrid.data;
}

