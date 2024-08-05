#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

#define OUT_RANGE 10e9 + 10

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    /*
        搜索二叉树最重要性质：左子树 < 根节点 < 右子树
        如果root.val < p.val, p在root右子树中
        如果root.val > p.val, p在root左子树中
        如果root.val = p.val, p和root指向同一个节点
    */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (p->val > q->val)
            swap(p, q);         // 确保q的值更大
        while(root != nullptr)
        {
            if(root->val > q->val)
            {
                root = root->left;  // 进入左子树遍历
            }
            else if(root->val < p->val)
            {
                root = root->right;
            }
            else
            {
                break;
            }
        }
        return root;

    }
};

int main()
{
    vector<int> vec = {6, 2, 8, 0, 4, 7, 9, INT_MIN, INT_MIN, 3, 5};
    TreeNode *root = genTree(vec);
    Solution *s = new Solution();

    return 0;
}