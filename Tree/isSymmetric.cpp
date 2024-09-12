#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// 对称二叉树
// 检查两个轴是否对称
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
    // 思路：检查左节点的右节点与右节点的左节点，左节点的左节点与右节点的右节点值是否相同
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        return dfs(root->left, root->right);
    }

private:
    bool dfs(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr || right == nullptr)
        {
            if (left == right)
            {
                return true;
            }
            return false;
        }
        return left->val == right->val && dfs(left->left, right->right) && dfs(left->right, right->left);
    }
};

int main()
{
    return 0;
}