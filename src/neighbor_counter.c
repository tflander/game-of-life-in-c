#include "neighbor_counter.h"

bool notMe(int c, int r, int col, int row) {
    return r != row || c != col;
}

bool inGrid(int c, int r, int numCols, int numRows) {
    return c > -1 && r > -1 && c < numCols && r < numRows;
}

int count_neighbors(struct Grid grid, struct Point point) {
    int count = 0;
    for (int c = point.x - 1; c <= point.x + 1; ++c) {
        for (int r = point.y - 1; r <= point.y + 1; ++r) {
            if(notMe(c,r,point.x,point.y) && inGrid(c, r, grid.numCols, grid.numRows)) {
                char x = getCell(grid, (struct Point){.x=c, .y=r});
                if(x == 'X') {
                    ++count;
                }
            }
        }
    }
    return count;
}
