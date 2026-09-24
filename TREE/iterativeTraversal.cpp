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
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> preorder;
        if (root == nullptr)
            return preorder;

        stack<TreeNode *> st;
        st.push(root);

        while (!st.empty())
        {
            root = st.top();
            st.pop();
            preorder.push_back(root->val);

            if (root->right != nullptr)
            {
                st.push(root->right);
            }
            if (root->left != nullptr)
            {
                st.push(root->left);
            }
        }
        return preorder;
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        TreeNode *node = root;
        vector<int> inorder;

        while (true)
        {
            if (node != nullptr)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                if (st.empty() == true)
                    break;
                node = st.top();
                st.pop();
                inorder.push_back(node->val);
                node = node->right;
            }
        }
        return inorder;
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> postorder;
        if (root == nullptr)
            return postorder;
        stack<TreeNode *> st1 ,st2;
        st1.push(root);
        while (!st1.empty())
        {
            root = st1.top();
            st1.pop();
            st2.push(root);
            if (root->left != nullptr)
                st1.push(root->left);
            if (root->right != nullptr)
                st1.push(root->right);
        }
        while(!st2.empty()){
            postorder.push_back(st2.top()->val);
            st2.pop();
        }
        return postorder;
    }
};