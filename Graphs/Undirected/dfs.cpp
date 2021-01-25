#include "graph.h"

#include <vector>
#include <stack>

// This program uses a depth-first search to determine
// whether there's a path between two vertices in an
// undirected graph

bool reach(graph g, int x, int y)
{
  if (x == y)
    return true;

  // a vector of visited vertices
  std::vector<bool> visited(g.numVertices(), false);

  // a stack of vertices to explore
  std::stack<int> stack;

  // start exploring from x
  stack.push(x);

  // Running a loop until all reachable vertices are explored
  while (!stack.empty())
  {
    // The vertice v is to be explored at this iteration
    int v = stack.top();
    stack.pop();
    std::list<int> neighbors = g.getNeighbors(v);

    for (auto neighbor : neighbors)
    {
      // if the destination is found, return true
      if (neighbor == y)
        return true;

      // If the vertex hasn't been visited, it is pushed
      // into the stack and marked as visited to avoid
      // processing it more than once
      if (!visited[neighbor])
      {
        stack.push(neighbor);
        visited[neighbor] = true;
      }
    }
  }
  // This line is reached only if the path haven't been found
  return false;
}

int main(int argc, char const *argv[])
{
  graph g(10);
  g.addEdge(1, 2);
  g.addEdge(1, 3);
  g.addEdge(2, 6);
  g.addEdge(4, 9);
  g.addEdge(5, 6);
  g.addEdge(5, 10);

  if (reach(g, 1, 10))
  {
    std::cout << "Reachable" << std::endl;
  }
  else
  {
    std::cout << "Not reachable" << std::endl;
  }

  return 0;
}
