#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

// 二叉树中的最大路径和
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 思路：最大路径为当前节点val + 左路径max + 右路径max
class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        dfs(root);
        return this->ret_;
    }

private:
    int ret_ = INT_MIN;
    int dfs(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int l = dfs(root->left);
        int r = dfs(root->right);
        ret_ = max(root->val + (l > 0 ? l : 0) + (r > 0 ? r : 0), ret_); // 如果子树值对当前值无增益，就不用加上子树值了
        return max(root->val + (l > 0 ? l : 0), root->val + (r > 0 ? r : 0));
    }
};

int main()
{
    return 0;
}