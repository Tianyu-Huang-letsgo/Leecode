#include <vector>
#include <stdio.h>
#include <iostream>
#include <queue>

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

TreeNode *genTree(vector<int> vec)
{
    if (vec.empty())
        return nullptr;

    // 创建根节点
    TreeNode *root = new TreeNode(vec[0]);
    std::queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);
    int i = 1;

    // 按层次顺序构建二叉树
    while (!nodeQueue.empty() && i < vec.size())
    {
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();

        // 处理左子节点
        if (i < vec.size() && vec[i] != INT_MIN)
        {
            node->left = new TreeNode(vec[i]);
            nodeQueue.push(node->left);
        }
        i++;

        // 处理右子节点
        if (i < vec.size() && vec[i] != INT_MIN)
        {
            node->right = new TreeNode(vec[i]);
            nodeQueue.push(node->right);
        }
        i++;
    }

    return root;
}

class Solution
{
public:
    // 思路：使用递归实现，当前层返回左右子树的最大深度
    // 使用后序遍历，左右中，《中》时记录左右子树更大的深度
    int maxDepth(TreeNode *root)
    {
        int dep = dfs(root, 1);
        return dep;
    }

private:
    int dfs(TreeNode *root, int dep) // 记录当前层节点深度
    {
        if (root == nullptr)
        {
            return --dep;
        }
        int lef_dep = dfs(root->left, dep + 1);
        int right_dep = dfs(root->right, dep + 1);
        return lef_dep >= right_dep ? lef_dep : right_dep;
    }
};

int main()
{
    vector<int> vec = {1, 2};
    TreeNode *root = genTree(vec);
    Solution *s = new Solution();
    int dep = s->maxDepth(root);
    return 0;
}