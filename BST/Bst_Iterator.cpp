class BSTIterator {
private:
    stack<TreeNode*> st; // <--- Fixed stack type

    void pushAll(TreeNode* node) {
       while(node !=nullptr){
        st.push(node);
        node = node->left;
       }
    }

public:
    BSTIterator(TreeNode* root) { 
        pushAll(root); 
    }

    int next() {
        TreeNode* temp = st.top();
        st.pop();
        pushAll(temp->right);
        return temp->val;
    }

    bool hasNext() { 
        return !st.empty(); 
    }
};
