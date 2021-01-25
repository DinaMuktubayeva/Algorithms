#include <iostream>
#include <vector>

using std::pair;
using std::vector;

bool hasCycle(vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &recStack, int v)
{
  // if we haven't explored this node, there might be a cycle
  if (!visited[v])
  {
    // mark as visited to avoid exploring it twice or more
    visited[v] = true;

    // put it into the current recursion stack to check for cyclicity
    recStack[v] = true;
    vector<int> neighbors = adj[v];

    // for each of the neighbors, check for a cycle
    for (auto neighbor : neighbors)
    {
      // a cycle is detected is an unvisited node is in the recursion stack
      if (!visited[neighbor] && hasCycle(adj, visited, recStack, neighbor))
        return true;
      else if (recStack[neighbor])
        return true;
    }
  }

  // This line is reached only if there is no cycle for the current
  // recursion stack
  // Therefore, reset the stack by setting all elements that were true in
  // the recursion stack to false
  recStack[v] = false;

  return false;
}

int acyclic(vector<vector<int>> &adj)
{
  vector<bool> visited(adj.size());
  vector<bool> recStack(adj.size());

  for (size_t i = 0; i < visited.size(); i++)
  {
    if (hasCycle(adj, visited, recStack, i))
      return true;
  }

  return 0;
}

int main()
{
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  for (size_t i = 0; i < m; i++)
  {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
