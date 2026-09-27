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

class Solution {
public:
    int diameter = 0;
    int checkH(TreeNode* node) {
        if (node == 0)
            return 0;
        int leftH = checkH(node->left);
        int rightH = checkH(node->right);

        diameter = max(diameter, leftH + rightH);
        return 1 + max(leftH, rightH);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        checkH(root);
        return diameter;
    }
};