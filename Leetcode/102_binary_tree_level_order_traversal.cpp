#include <queue>
#include <vector>
#include <iostream>

using std::queue;
using std::vector;

// Given a binary tree, return the level order traversal of its nodes'
// values. (ie, from left to right, level by level).

// Definition for a binary tree node.
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode *root)
{
  vector<vector<int>> levels; // the vector to return

  if (!root)
    return levels;

  if (!root->left && !root->right)
  {
    vector<int> level = {root->val};
    levels.push_back(level);
    return levels;
  }

  TreeNode *cur = root;
  vector<int> level = {cur->val}; // this vector will store all values at the current level

  levels.push_back(level);
  queue<TreeNode *> children; // a queue for BFS

  // filling the queue for the first level processing
  if (root->left)
    children.push(root->left);
  if (root->right)
    children.push(root->right);

  // iterate over levels
  while (!children.empty())
  {
    level.clear(); // clear before processing

    // process only nodes at the current level to fill the level vector
    // put their children into the queue from left to right for the
    // next while loop iteration
    int levelSize = children.size();
    for (size_t i = 0; i < levelSize; ++i)
    {
      cur = children.front();
      level.push_back(cur->val);

      if (cur->left)
        children.push(cur->left);
      if (cur->right)
        children.push(cur->right);

      children.pop();
    }

    levels.push_back(level); // put the filled level into the vector of levels
  }

  return levels;
}

int main(int argc, char const *argv[])
{
  TreeNode fourth(4);
  TreeNode third(3);
  TreeNode second(2, &fourth, &third);
  TreeNode first(1, &second, nullptr);

  vector<vector<int>> levels = levelOrder(&first);

  std::cout << "[";
  for (auto i : levels)
  {
    std::cout << "[";
    for (auto j : i)
    {
      std::cout << " " << j << " ";
    }
    std::cout << "] ";
  }
  std::cout << "] ";

  return 0;
}