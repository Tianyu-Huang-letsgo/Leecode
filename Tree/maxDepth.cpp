#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

// 二叉树的最大深度
// 定义：指从根节点到最远叶子节点的最长路径上的《节点数》
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
    int maxDepth(TreeNode *root)
    {
        return dfs(root, 1);
    }

private:
    int dfs(TreeNode *root, int dep)
    {
        if (root == nullptr)
        {
            return --dep; // 返回上一层（叶子节点）深度
        }
        return max(dfs(root->left, dep + 1), dfs(root->right, dep + 1));
    }
};

int main()
{
    return 0;
}
