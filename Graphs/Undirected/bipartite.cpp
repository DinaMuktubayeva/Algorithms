#include <iostream>
#include <vector>
#include <queue>

using std::queue;
using std::vector;

int bipartite(vector<vector<int>> &adj)
{
  vector<bool> visited(adj.size(), false); // marking vertices visited in a BFS
  vector<int> color(adj.size(), 0);        // the color of a vertex can be either 0 or 1

  // queue for BFS, which will begin with the vertex 0
  queue<int> queue;
  queue.push(0);

  // BFS iterating over layers of vertices' neighbors and coloring
  // them. Note that the neighboring layers should be colored
  // differently in a bipartite graph
  while (!queue.empty())
  {
    int v = queue.front();
    queue.pop();
    vector<int> neighbors = adj[v];

    for (int neighbor : neighbors)
    {
      // If the neighbor has been visited, and hence colored, and its
      // color is the same as the color of the vertex, this means that
      // this vertex is connected to an odd and an even layer, and
      // this isn't a bipartite graph
      if (visited[neighbor] && color[neighbor] == color[v])
      {
        return 0;
      }
      // If we haven't visited the neighbor, we color it 1 if the
      // current vertex is colored 0, and vice versa We push it to the
      // queue to later visit its neighbors as well
      else if (!visited[neighbor])
      {
        color[neighbor] = 1 - color[v];
        queue.push(neighbor);
      }

      // We have colored all the neighbors, which means, we have
      // visited the vertex!
      visited[v] = true;
    }
  }

  // This line can only be reached is there were no color conflicts
  // during BFS. Therefore, 1 is returned for a bipartite graph
  return 1;
}

int main()
{
  int n, m;
  std::cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  for (int i = 0; i < m; i++)
  {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
