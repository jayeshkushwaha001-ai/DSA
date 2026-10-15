/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode* left;
 *     TreeNode* right;
 * };
 */

class Solution {
public:
    vector<int> findMinMax(TreeNode* root) {
       vector<int> ans;
       TreeNode* node = root;
       if(root == nullptr) return ans;
       while(node->left!=nullptr){
        node = node->left; 
       }
       ans.push_back(node->val);
       node = root;
       while(node->right != nullptr){
        node = node->right;
       }
       ans.push_back(node->val);

       return ans;
    }
};
