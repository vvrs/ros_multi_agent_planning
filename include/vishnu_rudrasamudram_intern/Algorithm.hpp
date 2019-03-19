#pragma once

#include<limits>
#include<queue>
#include<algorithm>
#include<map>

#define EDGE_COST 10
#define GRID_SIZE_H 10
#define GRID_SIZE_W 10
#define FREE_CELL 0
#define OCC_CELL 1
namespace multi_agent_planner{

class Dijkstra
{
    typedef std::pair<int,int> position;
    public:

        Dijkstra();
        std::map<position, std::vector<position>> ComputeMap(std::vector<std::vector<int>>&);
        std::vector<position> Search(std::vector<std::vector<int>>&, position&, position&);
        virtual ~Dijkstra();
};

template<typename T, typename priority_t>
struct PriorityQueue {
  typedef std::pair<priority_t, T> PQElement;
  std::priority_queue<PQElement, std::vector<PQElement>,
                 std::greater<PQElement>> elements;

  inline bool empty() const {
     return elements.empty();
  }

  inline void push(T item, priority_t priority) {
    elements.emplace(priority, item);
  }

  T get() {
    T best_item = elements.top().second;
    elements.pop();
    return best_item;
  }
};

}