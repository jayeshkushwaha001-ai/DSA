#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class solution
{
    int findFloor(TreeNode *root, int key)
    {
        int floor = -1;
        while (root)
        {
            if (key == root->val)
            {
                floor = root->val;
                return floor;
            }
            if (key < root->val)
            {
                root = root->left;
            }
            else
            {
                floor = root->val;
                root = root->right;
            }
            return floor;
        }
    }
};
