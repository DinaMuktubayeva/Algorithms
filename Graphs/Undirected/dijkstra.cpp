#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using std::pair;
using std::priority_queue;
using std::queue;
using std::vector;

typedef pair<int, int> iPair;

long long distance(vector<vector<int>> &adj, vector<vector<int>> &cost, int s, int t)
{
  vector<int> dist(adj.size(), INT_MAX);
  dist[s] = 0;

  priority_queue<iPair, vector<iPair>, std::greater<iPair>> queue;
  queue.push(std::make_pair(0, s));

  while (!queue.empty())
  {
    int v = queue.top().second;
    queue.pop();

    vector<int> neighbors = adj[v];

    for (size_t i = 0; i < neighbors.size(); i++)
    {
      int neighbor = neighbors[i];
      if (dist[neighbor] > dist[v] + cost[v][i])
      {
        dist[neighbor] = dist[v] + cost[v][i];
        queue.push(std::make_pair(dist[neighbor], neighbor));
      }
    }
  }

  return dist[t] == INT_MAX ? -1 : dist[t];
}

int main()
{
  int n, m;
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
