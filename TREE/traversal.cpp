
#include<iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};
// PRE-ORDER(t.c = o(n) , s.c = o(n))
void preorder(node* node){
if(node == nullptr) return;
cout<<(node->data)<<" ";
preorder(node->left);
preorder(node->right);
}

// INORDER
void inorder(node* node){
if(node == nullptr) return;
inorder(node->left);
cout<<(node->data)<<" ";
inorder(node->right);
}
// POSTORDER
void postorder(node* node){
if(node == nullptr) return;
postorder(node->left);
postorder(node->right);
cout<<(node->data)<<" ";
}


int main() {
    node* root = new node{1, nullptr, nullptr};
    root->left = new node{2, nullptr, nullptr};
    root->right = new node{3, nullptr, nullptr};
    root->left->left = new node{4, nullptr, nullptr};

    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;

    return 0;
}