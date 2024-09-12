#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// 中序遍历
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {

        inorder(root);
        return this->ret_;
    }

private:
    vector<int> ret_;
    void inorder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        inorder(root->left);
        this->ret_.push_back(root->val);
        inorder(root->right);
    }
};

int main()
{
    return 0;
}
