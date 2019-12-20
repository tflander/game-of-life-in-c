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

}
