#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <set>
#include <climits>
#include <queue>

/*
Finding the shortest total length of all edges in a tree resulted
from connecting all given points on a coordinate plane

1. Insert the 0th point into the tree and push the distances from it
   to all other points into the priority queue
2. Take the closest point from the queue that isn't in the tree,
   insert it into the tree and update the result
3. If that point wasn't in the tree, push distances from that point to
   other points that aren't in the tree into the queue
4. Repeat until all the points are in the tree

main()
Input format 
1st line: n - number of points
each of the next n lines: x y - coordinates of a point

prim()
Implementation of Prim's algorithms

getDistance()
returns the distance between two points on a coordinate plane

*/

using std::pair;
using std::priority_queue;
using std::set;
using std::vector;

typedef pair<double, int> myPair;

double getDistance(int x1, int y1, int x2, int y2)
{
  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double prim(vector<int> x, vector<int> y)
{
  double result = 0.;

  priority_queue<myPair, vector<myPair>, std::greater<myPair>> queue;

  set<int> tree;

  // 1. Insert the 0th point into the tree and push the distances from
  //    it to all other points into the priority queue
  tree.insert(0);
  for (size_t i = 1; i < x.size(); i++)
    queue.push(std::make_pair(getDistance(x[0], y[0], x[i], y[i]), i));

  // Adding all points one by one into the tree
  while (!queue.empty())
  {
    // 2. Take the closest point from the queue that isn't in the tree,
    //    insert it into the tree and update the result
    myPair v = queue.top();
    double newDist = v.first;
    int newVertex = v.second;
    queue.pop();

    if (!tree.count(newVertex))
    {
      tree.insert(newVertex);
      result += newDist;

      for (size_t i = 1; i < x.size(); i++)
      {
        // 3. If that point wasn't in the tree, push distances from that point
        //    to other points that aren't in the tree into the queue
        if (!tree.count(i))
          queue.push(std::make_pair(getDistance(x[newVertex], y[newVertex], x[i], y[i]), i));
      }
    }
  }

  return result;
}

int main()
{
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << prim(x, y) << std::endl;
}
