#include <string>
#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::string;
using std::vector;

typedef map<char, int> edges;
typedef vector<edges> trie;

trie build_trie(vector<string> &patterns)
{
  trie t;
  int curNode;
  int numEdges = 0;

  // iterate over the strings
  for (size_t i = 0; i < patterns.size(); i++)
  {
    curNode = 0; // start from the root for every new string

    for (size_t j = 0; j < patterns[i].size(); j++)
    {
      char curChar = patterns[i].at(j);

      // if we haven't reached this level before (the trie is empty or
      // the last index of the trie is smaller than the index of the
      // current character)
      if (t.empty() || t.size() - 1 < j)
      {
        edges newEdge = {{curChar, ++numEdges}};
        t.push_back(newEdge);
        curNode = numEdges;
      }
      else if (curNode == numEdges)
      {
        while (t.size() != curNode)
        {
          edges newEdge;
          t.push_back(newEdge);
        }

        edges newEdge = {{curChar, ++numEdges}};
        t.push_back(newEdge);
        curNode = numEdges;
      }
      // if there's a chance that the character is present at this level
      else
      {
        // if the character isn't at this level
        if (!t[curNode].count(curChar))
        {
          // adding a new edge
          t[curNode][curChar] = ++numEdges;
          curNode = numEdges;
        }
        // if the character exists at this level
        else
        {
          curNode = t[curNode][curChar];
        }
      }
    }
  }

  return t;
}

int main()
{
  size_t n;
  std::cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++)
  {
    string s;
    std::cin >> s;
    patterns.push_back(s);
  }

  trie t = build_trie(patterns);
  for (size_t i = 0; i < t.size(); ++i)
  {
    for (const auto &j : t[i])
    {
      std::cout << i << "->" << j.second << ":" << j.first << "\n";
    }
  }

  return 0;
}