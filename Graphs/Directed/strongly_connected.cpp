#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using std::pair;
using std::stack;
using std::vector;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, stack<int> &order, int v)
{
  visited[v] = true;

  vector<int> neighbors = adj[v];
  for (auto neighbor : neighbors)
  {
    if (!visited[neighbor])
    {
      visited[neighbor] = true;
      dfs(adj, visited, order, neighbor);
    }
  }

  order.push(v);
}

int number_of_strongly_connected_components(vector<vector<int>> &adj)
{
  int result = 0;

  // Creating a reverse graph
  vector<vector<int>> reverse(adj.size());

  for (size_t i = 0; i < adj.size(); i++)
  {
    vector<int> neighbors = adj[i];
    for (auto neighbor : neighbors)
      reverse[neighbor].push_back(i);
  }

  vector<bool> visited(adj.size(), false);
  stack<int> order;

  // DFS on the reverse graph
  // This will create a stack of vertices in postorder
  for (size_t i = 0; i < adj.size(); i++)
  {
    if (!visited[i])
      dfs(reverse, visited, order, i);
  }

  vector<bool> visited2(adj.size(), false);

  // Taking vertices from the stack and performing DFS on the graph
  // The top-most vertex is in the sink of a reverse graph, the
  // bottom-most vertex is in the sink of the original graph
  // Therefore, by marking the visited vertices, we will be able to
  // distinguish the strongly connected components
  while (!order.empty())
  {
    int v = order.top();
    order.pop();

    if (!visited2[v])
    {
      stack<int> order2;
      dfs(adj, visited2, order2, v);
      result++;
    }
  }

  return result;
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
  std::cout << number_of_strongly_connected_components(adj);
}
