#include <algorithm> // for std::find
#include <list>

#include "graph.h"

graph::graph(const graph &g) : adj(new std::list<int>[g.num_vertices]),
                               num_vertices(g.num_vertices),
                               num_edges(g.num_edges)
{
  for (size_t i = 0; i < g.num_vertices; i++)
    adj[i] = g.adj[i];
}

graph &graph::operator=(const graph &g)
{
  clear();
  delete[] adj;
  adj = new std::list<int>[g.num_vertices];

  for (size_t i = 0; i < g.num_vertices; i++)
    adj[i] = g.adj[i];

  num_vertices = g.num_vertices;
  num_edges = g.num_edges;

  return *this;
}

bool graph::operator==(const graph &g) const
{
  if (num_vertices == g.num_vertices && num_edges == g.num_edges)
  {
    for (size_t i = 0; i < num_vertices; i++)
    {
      if (adj[i] != g.adj[i])
        return false;
    }

    return true;
  }
  return false;
}

bool graph::operator!=(const graph &g) const
{
  return !(*this == g);
}

void graph::addEdge(int x, int y)
{
  adj[x - 1].push_back(y);
  adj[y - 1].push_back(x);
  num_edges++;
}

bool graph::hasEdge(int x, int y)
{
  return std::find(adj[x - 1].begin(), adj[x - 1].end(), y) != adj[x - 1].end() &&
         std::find(adj[y - 1].begin(), adj[y - 1].end(), x) != adj[y - 1].end();
}

void graph::removeEdge(int x, int y)
{
  if (hasEdge(x, y))
  {
    // Since the vertices' numbers are unique, we can safely use
    // remove, which deletes all occurences of an element in a list
    adj[x - 1].remove(y);
    adj[y - 1].remove(x);
  }

  num_edges--;
}

std::list<int> graph::getNeighbors(int v)
{
  return adj[v - 1];
}

void graph::clear()
{
  for (size_t i = 0; i < num_vertices; ++i)
  {
    adj[i].clear();
  }

  num_vertices = 0;
  num_edges = 0;
}

bool graph::empty() const { return num_vertices == 0; }

size_t graph::numVertices() const { return num_vertices; }

size_t graph::numEdges() const { return num_edges; }

graph::~graph()
{
  this->clear();
  delete[] adj;
}