#include <stdbool.h>
#include <unity_fixture.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "gameOfLife.h"
#include "rules.h"
#include "render.h"
#include "neighbor_counter.h"
#include "support.h"

// const int numCols = 23;
// const int numRows = 10;
// char gridData[numRows][numCols];
// struct Grid grid = (struct Grid){(char*)gridData, numRows, numCols};

const int numColsForRandomTests = 23;
const int numRowsForRandomTests = 10;
char randomGridData[numRowsForRandomTests][numColsForRandomTests];
struct Grid randomGrid = (struct Grid){(char*)randomGridData, numRowsForRandomTests, numColsForRandomTests};

TEST_GROUP(Random);

TEST_SETUP(Random) {
    randomizeGrid(randomGrid, time(0));
}

TEST_TEAR_DOWN(Random) {
}

TEST(Random, random)
{
    display(randomGrid);

    for (int i = 0; i < 10; ++i) {
        sleep(1);
        tick(randomGrid);
        display(randomGrid);
    }
}

TEST_GROUP_RUNNER(Random)
{
    RUN_TEST_CASE(Random, random);
}

