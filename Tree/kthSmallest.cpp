#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// 230. 二叉搜索树中第k小的元素
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 思路：BST最重要的性质是对其进行中序遍历，是顺序列表
class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        dfs(root, k);
        return this->ret_;
    }

private:
    int ret_;
    void dfs(TreeNode *root, int &k)
    {
        if (root == nullptr)
        {
            return;
        }

        dfs(root->left, k);
        --k;
        if (k == 0)
        {
            ret_ = root->val;
        }
        dfs(root->right, k);
    }
};

int main()
{
    return 0;
}