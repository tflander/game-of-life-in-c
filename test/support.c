#include "support.h"
#include "render.h"
#include <unity_fixture.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

void verifyRow(struct Grid grid, int rowIndex, char* expected) {
    char actual[grid.numCols + 1];
    rowAsString(actual, grid, rowIndex);
    if(0 != strcmp(expected, actual)) {
        char msg[255];
        sprintf(msg, "Error in row %d.  Expected %s, found %s", rowIndex, expected, actual);
        TEST_FAIL_MESSAGE(msg);
    }
}

void verifyGrid(struct Grid grid, ...) {
    va_list ap; 
    va_start(ap, grid); 
  
    for (int r = 0; r < grid.numRows; ++r) {
        char* row = va_arg(ap, char*); 
        verifyRow(grid, r, row);
    }
  
    va_end(ap); 
}
