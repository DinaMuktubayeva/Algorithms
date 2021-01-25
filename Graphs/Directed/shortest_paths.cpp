#include <climits>
#include <iostream>
#include <limits>
#include <vector>
#include <queue>

using std::pair;
using std::priority_queue;
using std::queue;
using std::vector;
void negativeCycle(int v, vector<vector<int>> &adj, vector<int> &shortest)
{
  shortest[v] = 0;
  vector<int> neighbors = adj[v];
  for (size_t i = 0; i < neighbors.size(); i++)
  {
    if (shortest[neighbors[i]])
      negativeCycle(neighbors[i], adj, shortest);
  }
}
void shortest_paths(vector<vector<int>> &adj, vector<vector<int>> &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest)
{
  int v = adj.size(); // number of vertices

  for (size_t i = 0; i < v; i++)
  {
    if (i == s)
    {
      distance[i] = 0;
      reachable[i] = 1;
      shortest[i] = 1;
    }
    else
    {
      distance[i] = INT_MAX;
      reachable[i] = 0;
      shortest[i] = 1;
    }
  }

  // Getting shortest paths assuming there're no negative cycles
  for (size_t k = 0; k < v - 1; k++)
  {

    for (size_t i = 0; i < v; i++)
    {
      vector<int> neighbors = adj[i];

      for (size_t j = 0; j < neighbors.size(); j++)
      {
        int neighbor = neighbors[j];

        // if a vertex is reachable, its neighbors are reachable
        if (reachable[i])
          reachable[neighbor] = 1;

        // if the distance can be shortened
        if (distance[i] != INT_MAX && distance[neighbor] > distance[i] + cost[i][j])
        {
          distance[neighbor] = distance[i] + cost[i][j];
          reachable[neighbor] = 1;
        }
      }
    }
  }

  // Checking for negative cycles
  for (size_t i = 0; i < v - 1; i++)
  {
    vector<int> neighbors = adj[i];

    for (size_t j = 0; j < neighbors.size(); j++)
    {
      int neighbor = neighbors[j];

      if (!reachable[neighbor])
        shortest[neighbor] = 0;

      if (distance[i] != INT_MAX && distance[neighbor] > distance[i] + cost[i][j])
      {
        negativeCycle(neighbor, adj, shortest);
      }
    }
  }

  distance[s] = 0;

  // for (size_t j = 0; j < neighbors.size(); j++)
  // {
  //   int neighbor = neighbors[j];

  //   if (!reachable[neighbor] || distance[neighbor] > distance[i] + cost[i][j])
  //   {
  //     shortest[neighbor] = 0;
  //   }
  // }
}

int main()
{
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  vector<vector<int>> cost(n, vector<int>());
  for (int i = 0; i < m; i++)
  {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cin >> s;
  s--;
  vector<long long> distance(n, std::numeric_limits<long long>::max());
  vector<int> reachable(n, 0);
  vector<int> shortest(n, 1);
  shortest_paths(adj, cost, s, distance, reachable, shortest);
  for (int i = 0; i < n; i++)
  {
    if (!reachable[i])
    {
      std::cout << "*\n";
    }
    else if (!shortest[i])
    {
      std::cout << "-\n";
    }
    else
    {
      std::cout << distance[i] << "\n";
    }
  }
}
