/*
File : Algorithm.hpp
Vishnu Rudrasamudram
vishnu.rudrasamudram@gmail.com
*/

#pragma once

#include <limits>
#include <queue>
#include <algorithm>
#include <map>

#define EDGE_COST 10
#define GRID_SIZE_H 10
#define GRID_SIZE_W 10
#define FREE_CELL 0
#define OCC_CELL 1
namespace multi_agent_planner
{

class Dijkstra
{
  /**
   * @class Dijkstra
   * @brief Implements shortest path algorithm
   * 
   */

  // position of the agent in the grid
  typedef std::pair<int, int> position;

public:
  /**
 * @brief Construct a new Dijkstra object
 * 
 */
  Dijkstra();

  /**
   * @brief 
   * 
   * @return std::map<position, std::vector<position>> 
   */
  std::map<position, std::vector<position>> ComputeMap(std::vector<std::vector<int>> &);

  /**
   * @brief 
   * 
   * @return std::vector<position> 
   */
  std::vector<position> Search(std::vector<std::vector<int>> &, position &, position &);

  /**
   * @brief Destroy the Dijkstra object
   * 
   */
  virtual ~Dijkstra();
};

template <typename T, typename priority_t>
struct PriorityQueue
{
  /**
   * @struct PriorityQueue
   * @brief Priority queue to store the nodes to explore
   * 
   */

  typedef std::pair<priority_t, T> PQElement;

  // Defined to make to lower value to appear as top, because we need to get shortest path (low cost)
  std::priority_queue<PQElement, std::vector<PQElement>,
                      std::greater<PQElement>>
      elements;

  /**
   * @brief To check if the queue is empty
   * 
   * @return true Not empty
   * @return false Empty
   */
  inline bool empty() const
  {
    return elements.empty();
  }

  /**
 * @brief To add an element to the queue
 * 
 * @param item Node to be inserted and it's weight (cost in Dijkstra's case)
 * @param priority 
 */
  inline void push(T item, priority_t priority)
  {
    elements.emplace(priority, item);
  }

  /**
 * @brief Get the element
 * 
 * @return T Element with low cost
 */
  T get()
  {
    T best_item = elements.top().second;
    elements.pop();
    return best_item;
  }
};

} // namespace multi_agent_planner