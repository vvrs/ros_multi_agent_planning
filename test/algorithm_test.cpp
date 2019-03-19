#include <iostream>
#include <gtest/gtest.h>
#include <vector>

#include "vishnu_rudrasamudram_intern/Algorithm.hpp"

// using namespace multi_agent_planner;

TEST(Dijkstra, simpleTest)
{
    std::vector<std::vector<int> > world_state(GRID_SIZE_H,std::vector<int>(GRID_SIZE_W,FREE_CELL));
    std::pair<int, int> a = {0, 0};
    std::pair<int, int> b = {5, 0};

    multi_agent_planner::Dijkstra c;
    std::vector<std::pair<int, int>> path = c.Search(world_state, a, b);
    std::vector<std::pair<int, int>> expect = {{0,0},{1,0},{2,0},{3,0},{4,0},{5,0}};

    // for(const auto p : path)
    // {
    //     std::cout<<p.first<<" "<<p.second<<std::endl;
    // }

    ASSERT_EQ(expect.size(),path.size()) << "Result and expected vectors are of unequal length";

    for(int i=0;i<expect.size();++i)
    {
        EXPECT_EQ(expect[i],path[i]);
    } 

}
