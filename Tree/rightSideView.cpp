#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

// 二叉树的右视图
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 思路：采用层序遍历，每一层最后一个值就是最右侧的值
// 注意：不能使用dfs光对右值进行遍历，如果左子树深度更大，右视图后期可能都是左子树
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        queue<TreeNode *> que;
        que.push(root);
        vector<int> ret;
        while (!que.empty())
        {
            int cnt = que.size();
            for (int i = 1; i <= cnt; ++i)
            {
                TreeNode *node = que.front();
                que.pop();
                if (i == cnt)
                {
                    ret.push_back(node->val);
                }
                if (node->left != nullptr)
                {
                    que.push(node->left);
                }
                if (node->right != nullptr)
                {
                    que.push(node->right);
                }
            }
        }
        return ret;
    }
};

int main()
{
    return 0;
}