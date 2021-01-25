#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using std::pair;
using std::stack;
using std::vector;

void dfs(vector<vector<int>> &adj, vector<bool> &used, stack<int> &order, int x)
{
  // Mark the vertex as explored
  used[x] = true;

  // Do the DFS for all neighbors of the vertex
  vector<int> neighbors = adj[x];
  for (auto neighbor : neighbors)
  {
    if (!used[neighbor])
      dfs(adj, used, order, neighbor);
  }

  // At this point, all neighbors of the vertex are explored
  // Therefore, we can put it into the stack
  order.push(x);
}

stack<int> toposort(vector<vector<int>> adj)
{
  vector<bool> used(adj.size(), false);
  stack<int> order;

  // Do the DFS for every vertex that isn't explored
  for (size_t i = 0; i < adj.size(); i++)
  {
    if (!used[i])
      dfs(adj, used, order, i);
  }

  return order;
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

  stack<int> order = toposort(adj);

  size_t len = order.size();
  for (size_t i = 0; i < len; i++)
  {
    std::cout << order.top() + 1 << " ";
    order.pop();
  }
}
