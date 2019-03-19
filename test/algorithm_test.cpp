#include <iostream>
#include <gtest/gtest.h>
#include <vector>

#include "vishnu_rudrasamudram_intern/Algorithm.hpp"

using namespace multi_agent_planner;

TEST(Dijkstra, simpleTest)
{
    std::vector<std::vector<int> > world_state = {{0, 0, 0, 0, 0, 0},
                                                  {0, 0, 0, 0, 0, 0},
                                                  {0, 0, 0, 0, 0, 0},
                                                  {0, 0, 0, 0, 0, 0},
                                                  {0, 0, 0, 0, 0, 0},
                                                  {0, 0, 0, 0, 0, 0}};
    std::pair<int, int> a = {0, 0};
    std::pair<int, int> b = {5, 0};

    Dijkstra c;
    std::vector<std::pair<int, int>> path = c.search(world_state, a, b);
    std::vector<std::pair<int, int>> expect = {{0,0},{1,0},{2,0},{3,0},{4,0},{5,0}};

    ASSERT_EQ(expect.size(),path.size()) << "Result and expected vectors are of unequal length";

    for(int i=0;i<expect.size();++i)
    {
        EXPECT_EQ(expect[i],path[i]);
    } 

}
