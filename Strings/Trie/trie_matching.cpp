#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

// -- Description
// This program determines which of the given patterns occur in a
// given text using a trie and outputs the starting indexes at which
// pattern matches occur

// -- Representation
// The trie is a tree where each node has a unique number, and each
// edge represents a character. The trie is stored in memory as a
// vector of nodes

using namespace std;

int const Letters = 4;
int const NA = -1;

struct Node
{
  int next[Letters];

  Node()
  {
    fill(next, next + Letters, NA);
  }

  bool isLeaf() const
  {
    return (next[0] == NA && next[1] == NA && next[2] == NA && next[3] == NA);
  }
};

int letterToIndex(char letter)
{
  switch (letter)
  {
  case 'A':
    return 0;
    break;
  case 'C':
    return 1;
    break;
  case 'G':
    return 2;
    break;
  case 'T':
    return 3;
    break;
  default:
    assert(false);
    return -1;
  }
}

typedef vector<Node> trie;

trie buildTrie(const vector<string> &patterns)
{
  trie trie;
  Node root;
  trie.push_back(root);

  int curNode;
  int numNodes = 0; // for simplicity, don't count the root node

  // iterate over the strings
  for (size_t i = 0; i < patterns.size(); i++)
  {
    curNode = 0; // start from the root for every new string

    for (size_t j = 0; j < patterns[i].size(); j++)
    {
      char curChar = patterns[i].at(j);
      int curIdx = letterToIndex(curChar); // index corresponding to the current letter

      // Index of the next node corresponding to curChar
      int nextNode = trie[curNode].next[curIdx];

      // If there's no node corresponding to the current letter
      if (nextNode == NA)
      {
        // Add a new edge to the current node
        trie[curNode].next[curIdx] = ++numNodes;

        // Insert a new node into the trie
        Node newNode;
        trie.push_back(newNode);

        // Set the index of the current node to the index of the new node
        // (new branch in the trie)
        curNode = numNodes;
      }
      // If there's a node corresponding to the current letter
      else
      {
        // The index of the current node is set to the index of the next node
        // (going down the existing branch of the trie)
        curNode = nextNode;
      }
    }
  }

  return trie;
}

bool prefixMatching(int textLetterIdx, const string &text, const trie &trie)
{
  int nodeIdx = 0;
  Node curNode = trie[nodeIdx];
  char patternLetter = text[textLetterIdx];
  int patternLetterIdx = letterToIndex(patternLetter);

  while (true)
  {
    // If the current node is a leaf, there's a match
    if (curNode.isLeaf())
    {
      return true;
    }
    // If there's an edge corresponding to the current letter
    else if (curNode.next[patternLetterIdx] != NA)
    {
      // Update the current node
      nodeIdx = curNode.next[patternLetterIdx];
      curNode = trie[nodeIdx];

      // If this is the last letter in the text, we should return
      // since we cannot move forward anymore
      // There's a match if the current node (updated) is a leaf
      if (textLetterIdx == text.size() - 1)
        return curNode.isLeaf();

      // Update the current node and the current letter to the next
      // values (move down the branch)
      patternLetter = text[++textLetterIdx];
      patternLetterIdx = letterToIndex(patternLetter);
    }
    // If there's no branch to move down, there's no match
    else
    {
      return false;
    }
  }

  return false;
}

vector<int> solve(const string &text, int n, const vector<string> &patterns)
{
  vector<int> result;
  trie trie = buildTrie(patterns);

  // Iterate over all possible suffixes of the text
  for (size_t i = 0; i < text.size(); i++)
  {
    if (prefixMatching(i, text, trie))
      result.push_back(i);
  }

  return result;
}

int main(void)
{
  string t;
  cin >> t;

  int n;
  cin >> n;

  vector<string> patterns(n);
  for (int i = 0; i < n; i++)
  {
    cin >> patterns[i];
  }

  vector<int> ans;
  ans = solve(t, n, patterns);

  for (int i = 0; i < (int)ans.size(); i++)
  {
    cout << ans[i];
    if (i + 1 < (int)ans.size())
    {
      cout << " ";
    }
    else
    {
      cout << endl;
    }
  }

  return 0;
}
