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

struct SpikeGrid createGrid(int numRows, int numColumns) {

    char **grid = (char**) calloc(numRows, sizeof(char*));

    for ( int i = 0; i < numRows; i++ )
    {
        grid[i] = (char*) calloc(numColumns, sizeof(char));
    }

    struct SpikeGrid spikeGrid = {grid, numRows, numColumns};

    return spikeGrid;

}

TEST(Spike, foo) {

    // arrange
    int num_rows = 4;
    int num_columns = 3;

    struct SpikeGrid grid = createGrid(num_rows, num_columns);

    // act
    grid.data[1][2] = 'X';

    // assert
    TEST_ASSERT_EQUAL(0, grid.data[1][1]);
    TEST_ASSERT_EQUAL('X', grid.data[1][2]);

    // cleanup
    for ( int i = 0; i < num_rows; i++ )
    {
        free(grid.data[i]);
    }

    free(grid.data);

}

TEST_GROUP_RUNNER(Spike)
{
    RUN_TEST_CASE(Spike, foo);
}