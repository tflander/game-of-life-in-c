#include <stdbool.h>
#include <unity_fixture.h>
#include "rules.h"

TEST_GROUP(Rules);

TEST_SETUP(Rules) {}

TEST_TEAR_DOWN(Rules) {}

TEST(Rules, live_cell_with_fewer_than_two_neighbors_dies)
{
    TEST_ASSERT_FALSE(cell_alive(true, 1));
    TEST_ASSERT_FALSE(cell_alive(true, 0));
}

TEST_GROUP_RUNNER(Rules)
{
    RUN_TEST_CASE(Rules, live_cell_with_fewer_than_two_neighbors_dies);
}