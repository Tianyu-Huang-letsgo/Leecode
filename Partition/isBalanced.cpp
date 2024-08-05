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
    bool isBalanced(TreeNode *root)
    {
        dfs(root, 1);
        return ret_;
    }

private:
    bool ret_ = true;
    // 记录当前深度
    // 只要有一个节点的左右子树深度不平衡，判断该树不是平衡树
    // 要返回当前节点最深的值
    int dfs(TreeNode *root, int depth)
    {
        if (ret_ == false)
            return depth;
        if (root == nullptr)
        {
            return depth - 1;
        }
        int l_dep = dfs(root->left, depth + 1);
        int r_dep = dfs(root->right, depth + 1);
        if (abs(l_dep - r_dep) > 1)
        {
            ret_ = false;
        }
        return l_dep < r_dep ? r_dep : l_dep; // 返回左右子树最深的节点
    }
};

int main()
{
    vector<int> vec = {1, 2, 2, 3, 3, INT_MIN, INT_MIN, 4, 4};
    TreeNode *root = genTree(vec);
    Solution *s = new Solution();
    bool ret = s->isBalanced(root);
    return 0;
}