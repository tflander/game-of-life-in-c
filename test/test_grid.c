#include <stdbool.h>
#include <unity_fixture.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "rules.h"
#include "render.h"
#include "neighbor_counter.h"

const int numCols = 4;
const int numRows = 3;
char gridData[numCols][numRows];

struct Grid grid = {(char*)gridData, numCols, numRows};
void verifyGrid(struct Grid grid, ...);

TEST_GROUP(Grid);

TEST_SETUP(Grid) {
    wipeGrid(grid);
}
TEST_TEAR_DOWN(Grid) {}

TEST(Grid, create_empty_grid) {

    for(int c = 0; c < numCols; ++c) {
       for(int r = 0; r < numRows; ++r) {
           TEST_ASSERT_EQUAL(' ', gridData[c][r]);
       }
    }
}

TEST(Grid, set_grid_cell) {
    setLivingCell(grid, (struct Point){.x=1, .y=2});
    TEST_ASSERT_EQUAL('X', gridData[1][2]);
}

TEST(Grid, middle_cell_has_one_living_neighbor) {
    setLivingCell(grid, (struct Point){.x=0, .y=0});
    TEST_ASSERT_EQUAL(1, count_neighbors(grid, (struct Point){.x=1, .y=1}));
}

TEST(Grid, top_left_cell_has_one_living_neighbor) {
    setLivingCell(grid, (struct Point){.x=0, .y=1});
    TEST_ASSERT_EQUAL(1, count_neighbors(grid, (struct Point){.x=0, .y=0}));
}

TEST(Grid, bottom_right_cell_has_one_living_neighbor) {
    setLivingCell(grid, (struct Point){.x=3, .y=1});
    TEST_ASSERT_EQUAL(1, count_neighbors(grid, (struct Point){.x=3, .y=2}));
}

TEST(Grid, live_cell_with_fewer_than_two_neighbors_dies)
{
    setLivingCell(grid, (struct Point){.x=0, .y=0});
    tick(grid);
    TEST_ASSERT_FALSE(isAlive(grid, (struct Point){0, 0}));

}

TEST(Grid, live_cell_with_two_or_three_neighbors_survives)
{
    setGrid(grid,
        "XX  ",
        "X   ",
        "    "
    );
    tick(grid);
    TEST_ASSERT_TRUE(isAlive(grid, (struct Point){0, 0}));
}

TEST(Grid, live_cell_with_more_than_three_neighbors_dies)
{
    setGrid(grid,
        "XXX.",
        "XXX.",
        "...."
    );

    tick(grid);
    
    verifyGrid(grid,
        "X.X.",
        "X.X.",
        ".X.."
    );
    TEST_ASSERT_FALSE(isAlive(grid, (struct Point){.x=1, .y=0}));
}

TEST(Grid, dead_cell_with_three_neighbors_becomes_live)
{
   setGrid(grid,
        "X   ",
        "XX  ",
        "    "
    );
    tick(grid);
    TEST_ASSERT_TRUE(isAlive(grid, (struct Point){1, 0}));

}

TEST(Grid, dead_cell_with_two_neighbors_stays_dead)
{
    setGrid(grid,
        "XX  ",
        "    ",
        "    "
    );
    tick(grid);
    TEST_ASSERT_FALSE(isAlive(grid, (struct Point){1, 0}));
}


TEST_GROUP_RUNNER(Grid)
{
    RUN_TEST_CASE(Grid, create_empty_grid);
    RUN_TEST_CASE(Grid, set_grid_cell);
    RUN_TEST_CASE(Grid, middle_cell_has_one_living_neighbor);    
    RUN_TEST_CASE(Grid, top_left_cell_has_one_living_neighbor);
    RUN_TEST_CASE(Grid, bottom_right_cell_has_one_living_neighbor);

    RUN_TEST_CASE(Grid, live_cell_with_fewer_than_two_neighbors_dies);
    RUN_TEST_CASE(Grid, live_cell_with_two_or_three_neighbors_survives);
    RUN_TEST_CASE(Grid, live_cell_with_more_than_three_neighbors_dies);
    RUN_TEST_CASE(Grid, dead_cell_with_three_neighbors_becomes_live);
    RUN_TEST_CASE(Grid, dead_cell_with_two_neighbors_stays_dead);

}

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
