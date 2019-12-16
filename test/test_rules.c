#include <stdbool.h>
#include <unity_fixture.h>
#include "rules.h"

const int numCols = 4;
const int numRows = 3;
char gridData[numCols][numRows];

TEST_GROUP(Rules);
TEST_GROUP(Grid);

TEST_SETUP(Rules) {}
TEST_TEAR_DOWN(Rules) {}
TEST_SETUP(Grid) {
    wipeGrid((char*)gridData, numCols, numRows);
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
    setLivingCell((char*)gridData, numRows, 1,2);
    TEST_ASSERT_EQUAL('X', gridData[1][2]);
}

TEST(Grid, middle_cell_has_one_living_neighbor) {
    setLivingCell((char*)gridData, numRows, 0, 0);
    TEST_ASSERT_EQUAL(1, count_neighbors((char*)gridData, numCols, numRows, 1, 1));
}

TEST(Grid, top_left_cell_has_one_living_neighbor) {
    setLivingCell((char*)gridData, numRows, 0, 1);
    TEST_ASSERT_EQUAL(1, count_neighbors((char*)gridData, numCols, numRows, 0, 0));
}

TEST(Grid, bottom_right_cell_has_one_living_neighbor) {
    setLivingCell((char*)gridData, numRows, 3, 1);
    // print((char*)gridData, numCols, numRows);
    TEST_ASSERT_EQUAL(1, count_neighbors((char*)gridData, numCols, numRows, 3, 2));
}

TEST(Rules, live_cell_with_fewer_than_two_neighbors_dies)
{
    TEST_ASSERT_FALSE(cell_alive(true, 1));
    TEST_ASSERT_FALSE(cell_alive(true, 0));
}

TEST(Rules, live_cell_with_two_or_three_neighbors_survives)
{
    TEST_ASSERT_TRUE(cell_alive(true, 2));
    TEST_ASSERT_TRUE(cell_alive(true, 3));
}

TEST(Rules, live_cell_with_more_than_three_neighbors_dies)
{
    TEST_ASSERT_FALSE(cell_alive(true, 4));
    TEST_ASSERT_FALSE(cell_alive(true, 5));
}

TEST(Rules, dead_cell_with_three_neighbors_becomes_live)
{
    TEST_ASSERT_TRUE(cell_alive(false, 3));
}

TEST(Rules, dead_cell_with_two_neighbors_stays_dead)
{
    TEST_ASSERT_FALSE(cell_alive(false, 2));
}

TEST_GROUP_RUNNER(Rules)
{
    RUN_TEST_CASE(Rules, live_cell_with_fewer_than_two_neighbors_dies);
    RUN_TEST_CASE(Rules, live_cell_with_two_or_three_neighbors_survives);
    RUN_TEST_CASE(Rules, live_cell_with_more_than_three_neighbors_dies);
    RUN_TEST_CASE(Rules, dead_cell_with_three_neighbors_becomes_live);
    RUN_TEST_CASE(Rules, dead_cell_with_two_neighbors_stays_dead);

    RUN_TEST_CASE(Grid, create_empty_grid);
    RUN_TEST_CASE(Grid, set_grid_cell);
    RUN_TEST_CASE(Grid, middle_cell_has_one_living_neighbor);    
    RUN_TEST_CASE(Grid, top_left_cell_has_one_living_neighbor);
    RUN_TEST_CASE(Grid, bottom_right_cell_has_one_living_neighbor);

    // RUN_TEST_CASE(Grid, live_cell_with_fewer_than_two_neighbors_dies);
    // RUN_TEST_CASE(Grid, live_cell_with_two_or_three_neighbors_survives);
    // RUN_TEST_CASE(Grid, live_cell_with_more_than_three_neighbors_dies);
    // RUN_TEST_CASE(Grid, dead_cell_with_three_neighbors_becomes_live);
    // RUN_TEST_CASE(Grid, dead_cell_with_two_neighbors_stays_dead);

}