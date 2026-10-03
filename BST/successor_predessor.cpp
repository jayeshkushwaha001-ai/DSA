#include <vector>
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
    vector<int> succPrec(TreeNode *root, int key)
    {
        TreeNode *pred = nullptr;
        TreeNode *succ = nullptr;
        TreeNode *temp = root;
        while (temp != nullptr)
        {
            if (temp->val >= key)
            {
                temp = temp->left;
            }
            else
            {
                pred = temp;
                temp = temp->right;
            }
        }
        temp = root;
        while (temp != nullptr)
        {
            if (temp->val <= key)
            {
                temp = temp->right;
            }
            else
            {
                succ = temp;
                temp = temp->left;
            }
        }

        int preVal = (pred != nullptr) ? pred->val : -1;
        int sucVal = (succ != nullptr) ? succ->val : -1;
        return {preVal, sucVal};
    }
};
