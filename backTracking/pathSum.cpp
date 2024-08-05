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
    // 思路：记录当前节点路径和，遇到路径和=targetSum的则推入vector<vector<int>>
    // 简化：每一层输入targetSum - root->val
    // 注意审题：是从根节点到叶子节点路径总和，没到叶子节点的路径即使是达到了targetSum也不是答案
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> v;
        dfs(root, targetSum, v);
        return this->ret_;
    }

private:
    vector<vector<int>> ret_;
    void dfs(TreeNode *root, const int targetSum, vector<int> &vec)
    {
        if (root == nullptr)
        {
            return;
        }
        // 当前节点推进数组
        vec.push_back(root->val);
        // 注意题目要求，root->val有可能是负数
        // if (targetSum - root->val < 0)
        // {
        //     vec.pop_back();
        //     return;
        // }
        if (targetSum - root->val == 0 && root->left == nullptr && root->right == nullptr)
        {
            ret_.push_back(vec);
            vec.pop_back();
            return;
        }
        dfs(root->left, targetSum - root->val, vec);
        dfs(root->right, targetSum - root->val, vec);
        // 遍历完当前节点需要推出数组
        vec.pop_back();
    }
};

int main()
{
    vector<int> vec = {-2, INT_MIN, -3};
    TreeNode *root = genTree(vec);
    Solution *s = new Solution();
    vector<vector<int>> v = s->pathSum(root, -5);
    return 0;
}