#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

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
    // 只能想到数组排序后返回
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> vec;
        queue<TreeNode *> que;
        if (root != nullptr)
            que.push(root);

        while (!que.empty())
        {
            TreeNode *top = que.front();
            vec.push_back(top->val);
            que.pop();
            if (top->left != nullptr)
                que.push(top->left);
            if (top->right != nullptr)
                que.push(top->right);
        }
        sort(vec.begin(), vec.end(), [](int a, int b)
             { return a < b; });
        return vec[k - 1];
    }
};

class Solution_dfs
{
public:
    // 二叉搜索树中，任意子节点满足“左子节点 < 根节点 < 右子节点”
    // 二叉树非常重要的性质：中序遍历为递增
    int kthSmallest(TreeNode *root, int k)
    {
        this->k = k;
        dfs(root);
        return ret;
    }

private:
    int ret, k;
    void dfs(TreeNode *root)
    {
        if (root == nullptr)
            return;
        dfs(root->left);
        // 在二叉树递归遍历中，《中》的位置用来进行分析处理操作
        if (k == 0)
            return;
        if (--k == 0)
            this->ret = root->val;
        dfs(root->right);
    }
};

int main()
{
    vector<int> vec = {3, 1, 4, INT_MIN, 2};
    TreeNode *root = genTree(vec);
    Solution *s = new Solution();

    s->kthSmallest(root, 1);
    return 0;
}