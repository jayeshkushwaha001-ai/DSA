/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
   private:
    bool isLeaf(TreeNode* root) {
        return (root->left == nullptr && root->right == nullptr);
    }
    void addLeft(TreeNode* root, vector<int> &res) {
        TreeNode* curr = root->left;
        while (curr) {
            if (!isLeaf(curr)) res.push_back(curr->val);
            if (curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }
    void addLeaves(TreeNode* root, vector<int> &res) {
        if (isLeaf(root)) {
            res.push_back(root->val);
            return;
        }
        if (root->left) addLeaves(root->left, res);
        if (root->right) addLeaves(root->right, res);
    }

    void addRight(TreeNode* root, vector<int> &res) {
        TreeNode* curr = root->right;
        vector<int> temp;
        while (curr) {
            if (!isLeaf(curr)) temp.push_back(curr->val);
            if (curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }
        int n = temp.size() - 1;
        for (int i = n; i >= 0; i--) {
            res[i] = temp[n - i];
        }
    }

   public:
    vector<int> boundary(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        if (!isLeaf(root)) res.push_back(root->data);
        addLeft(root, res);
        addLeaves(root, res);
        addRight(root, res);
        return res;
    }
};
