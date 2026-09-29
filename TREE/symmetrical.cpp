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
    bool isSymmetric(TreeNode* root) {
        return root == nullptr || isSYM(root->left, root->right);
    }
    bool isSYM(TreeNode* left, TreeNode* right){
        if(left == nullptr || right == nullptr) return left==right;

        if(left->val != right->val) return false;

        return isSYM(left->right , right->left) && isSYM(left->left , right->right);
    }
};