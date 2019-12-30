#include <stdbool.h>
#include <unity_fixture.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <render.h>
#include "gameOfLife.h"
#include "rules.h"
#include "render.h"
#include "neighbor_counter.h"
#include "support.h"

const int numColsForGridTests = 4;
const int numRowsForGridTests = 3;
char gridData[numRowsForGridTests][numColsForGridTests];
struct Grid grid = (struct Grid){(char*)gridData, numRowsForGridTests, numColsForGridTests};

TEST_GROUP(Grid);

TEST_SETUP(Grid) {
    wipeGrid(grid);
}

TEST_TEAR_DOWN(Grid) {
}

TEST(Grid, create_empty_grid) {

    for(int r = 0; r < grid.numRows; ++r) {
        for(int c = 0; c < grid.numCols; ++c) {
           TEST_ASSERT_EQUAL(' ', getCell(grid, (struct Point){.x=c, .y=r}));
       }
    }
}

TEST(Grid, randomize_grid) {
    randomizeGrid(grid, time(0));
    int numMarks = 0;
    for(int r = 0; r < grid.numRows; ++r) {
        for(int c = 0; c < grid.numCols; ++c) {
            if ('X' == getCell(grid, (struct Point){.x=c, .y=r})) {
                ++numMarks;
            }
       }
    }
    int numCells = grid.numCols * grid.numRows;
    TEST_ASSERT_TRUE(numMarks > 0 && numMarks < numCells);
}

TEST(Grid, set_grid_cell) {
    setLivingCell(grid, (struct Point){.x=1, .y=2});  // good
    TEST_ASSERT_EQUAL('X', getCell(grid, (struct Point){.x=1, .y=2}));
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
    RUN_TEST_CASE(Grid, randomize_grid);
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
