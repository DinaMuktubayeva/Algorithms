#include "graph.h"

#include <vector>
#include <queue>

// This program calculates the number of components in an
// undirected graph

void bfs(int i, graph g, std::vector<bool> &visited)
{
  // a queue of vertices to explore
  std::queue<int> queue;
  queue.push(i);

  while (!queue.empty())
  {
    // The vertice v is to be explored at this iteration
    int v = queue.front();
    queue.pop();
    std::list<int> neighbors = g.getNeighbors(v);

    for (auto neighbor : neighbors)
    {
      // If the vertex hasn't been visited, it is pushed
      // into the queue and marked as visited to avoid
      // processing it more than once
      if (!visited[neighbor])
      {
        queue.push(neighbor);
        visited[neighbor] = true;
      }
    }
  }
}

int components(graph g)
{
  if (g.numVertices() == 1)
    return 1;

  // number of connected components
  int numComponents = 0;

  // a vector of visited vertices
  std::vector<bool> visited(g.numVertices(), false);

  // Running a loop until all reachable vertices are
  // explored
  for (size_t i = 1; i <= g.numVertices(); i++)
  {
    if (!visited[i])
    {
      bfs(i, g, visited);
      numComponents++;
    }
  }

  return numComponents;
}

int main(int argc, char const *argv[])
{
  graph g(10);
  g.addEdge(1, 2);
  // g.addEdge(1, 3);
  // g.addEdge(2, 6);
  // g.addEdge(4, 9);
  // g.addEdge(5, 6);
  // g.addEdge(5, 10);

  std::cout << "There are " << components(g) << " connected components" << std::endl;
  return 0;
}
