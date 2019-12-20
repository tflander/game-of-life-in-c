#include <unity_fixture.h>

struct SpikeGrid {
    char** data;
    int numRows;
    int numColumns;
};

TEST_GROUP(Spike);

TEST_SETUP(Spike) {
}
TEST_TEAR_DOWN(Spike) {}

struct SpikeGrid createEmptyGrid(int numRows, int numColumns) {

    char **grid = (char**) malloc(numRows * sizeof(char*));

    for ( int i = 0; i < numRows; i++ ) {
        grid[i] = (char*) malloc(numColumns * sizeof(char));

        for (int j = 0; j < numColumns; ++j) {
            grid[i][j] = ' ';
        }
    }

    struct SpikeGrid spikeGrid = {grid, numRows, numColumns};

    return spikeGrid;

}

void destroyGrid(struct SpikeGrid grid) {
   for ( int i = 0; i < grid.numRows; i++ )
    {
        free(grid.data[i]);
    }

    free(grid.data);    
}


TEST(Spike, foo) {

    struct SpikeGrid grid = createEmptyGrid(4, 3);

    // act
    grid.data[1][2] = 'X';

    // assert
    TEST_ASSERT_EQUAL(' ', grid.data[1][1]);
    TEST_ASSERT_EQUAL('X', grid.data[1][2]);

    // cleanup
    destroyGrid(grid);
}

TEST_GROUP_RUNNER(Spike)
{
    RUN_TEST_CASE(Spike, foo);
}