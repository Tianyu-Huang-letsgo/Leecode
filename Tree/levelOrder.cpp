#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

// 层序遍历
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
    // 难点：如何进行分层
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        queue<TreeNode *> que;
        que.push(root);
        vector<vector<int>> ret;
        while (!que.empty())
        {
            int cnt = que.size();
            vector<int> v;
            for (int i = 0; i < cnt; ++i)
            {
                TreeNode *node = que.front();
                que.pop();

                v.push_back(node->val);
                if (node->left)
                {
                    que.push(node->left);
                }
                if (node->right)
                {
                    que.push(node->right);
                }
            }
            ret.push_back(v);
        }
        return ret;
    }
};

int main()
{
    return 0;
}