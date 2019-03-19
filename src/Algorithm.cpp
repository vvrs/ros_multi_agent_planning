#include "vishnu_rudrasamudram_intern/Algorithm.hpp"

namespace multi_agent_planner
{

Dijkstra::Dijkstra()
{

}

std::map<Dijkstra::position, std::vector<Dijkstra::position> > Dijkstra::ComputeMap(std::vector<std::vector<int> >& world_state)
{
    std::map<Dijkstra::position, std::vector<Dijkstra::position> > m;

    for(int i = 0; i < int(world_state.size()); ++i){
        for(int j = 0; j < int(world_state.at(0).size()); ++j){

            std::vector<Dijkstra::position> adj;

            if((j - 1) >= 0 && world_state.at(i).at(j-1) == 0){
                adj.push_back(std::make_pair(i, j - 1));
            }

            if((i + 1) < int(world_state.size()) && world_state.at(i + 1).at(j) == 0){
                adj.push_back(std::make_pair(i + 1, j));
            }

            if((j + 1) < int(world_state.at(i).size()) && world_state.at(i).at(j + 1) == 0){
                adj.push_back(std::make_pair(i, j + 1));
            }

            if((i - 1) >= 0 && world_state.at(i - 1).at(j) == 0)
                adj.push_back(std::make_pair(i - 1, j));

            if(world_state.at(i).at(j) == 1)
                adj.clear();

            m.emplace(std::make_pair(i, j), adj);
            adj.clear();
        }
    }

    return m;
}

std::vector<Dijkstra::position> Dijkstra::search(std::vector<std::vector<int> >& env, Dijkstra::position& start, Dijkstra::position& goal)
{
    std::map<Dijkstra::position, std::vector<Dijkstra::position > > map = ComputeMap(env);
    std::map<Dijkstra::position, Dijkstra::position > came_from;
    std::map<Dijkstra::position, double> cost_so_far;

    PriorityQueue<Dijkstra::position, double> frontier;
    frontier.push(start, 0);

    came_from[start] = start;
    cost_so_far[start] = 0;

    while (!frontier.empty())
    {
        Dijkstra::position current = frontier.get();

        if (current == goal)
        {
          break;
        }

        auto search = map.find(current);

        for (Dijkstra::position next : search->second)
        {
            double new_cost = cost_so_far[current] + 1;
            if (cost_so_far.find(next) == cost_so_far.end() || new_cost < cost_so_far[next]) // cannot find next or new_cost less than cost_so_far
            {
                cost_so_far[next] = new_cost;
                frontier.push(next, new_cost);
                came_from[next] = current;
            }
        }
    }

    std::vector<Dijkstra::position> path;
    Dijkstra::position current = goal;
    while (current != start)
    {
        path.push_back(current);
        current = came_from[current];
    }

    path.push_back(start);

    if((std::abs(path.at(0).first - path.at(1).first) > 1) || (std::abs(path.at(0).second - path.at(1).second) > 1))
    {
        path.clear();
        return path;
    }
    std::reverse(path.begin(), path.end());
    return path;
}

Dijkstra::~Dijkstra()
{

}

} // 

