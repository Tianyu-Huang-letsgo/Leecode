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
    // 思路1：层序遍历将树推进数组，收尾比较，O(2N)
    // 思路2：左子树的左子树跟右子树的右子树比，左子树的右子树跟右子树的左子树比

    // 方法1：使用bfs(写起来相对麻烦)
    bool isSymmetric_bfs(TreeNode *root)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            return true;
        }
        queue<TreeNode *> que;
        que.push(root);

        while (!que.empty())
        {
            int cnt = que.size();
            vector<int> v;
            for (int i = 0; i < cnt; i++)
            {
                TreeNode *top = que.front();
                que.pop();
                if (top == nullptr)
                {
                    v.push_back(-110);
                }
                else
                {
                    v.push_back(top->val);
                    que.push(top->left);
                    que.push(top->right);
                }
            }
            if (v.size() != 1 && v.size() % 2 != 0)
            {
                return false;
            }
            int i = 0, j = v.size() - 1;
            while (i <= j)
            {
                if (v[i] != v[j])
                {
                    return false;
                }
                i++;
                j--;
            }
        }
        return true;
    }

    // 方法2：使用dfs
    bool isSymmetric(TreeNode *root)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            return true;
        }
        return dfs(root->left, root->right);
    }

private:
    // 输入两个要进行比较的节点
    bool dfs(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr && right == nullptr)
        {
            return true;
        }
        if (left == nullptr && right != nullptr || left != nullptr && right == nullptr)
        {
            return false;
        }
        if (left->val != right->val)
        {
            return false;
        }
        return dfs(left->left, right->right) && dfs(left->right, right->left);
    }
};

int main()
{
    vector<int> vec = {1, 2, 2, INT_MIN, 3, INT_MIN, 3};
    TreeNode *root = genTree(vec);
    Solution *s = new Solution();
    bool ret = s->isSymmetric(root);
    return 0;
}