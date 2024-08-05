#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <math.h>

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

class Solution
{
public:
    // 思路：还是按照原来顺序推进que，读取数字的时候根据标志位flag正反顺序读取
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        queue<TreeNode *> que;
        vector<vector<int>> ret;
        if (root != nullptr)
            que.push(root);
        int flag = -1;
        while (!que.empty())
        {
            int cnt = que.size();
            vector<int> tmp(cnt);
            for (int i = 0; i < cnt; i++)
            {
                TreeNode *top = que.front();
                que.pop();
                if (flag > 0)
                {
                    tmp[cnt - i - 1] = top->val;
                }
                else
                {
                    tmp[i] = top->val;
                }
                if (top->left != nullptr)
                {
                    que.push(top->left);
                }
                if (top->right != nullptr)
                {
                    que.push(top->right);
                }
            }
            flag = -flag;
            ret.push_back(tmp);
        }
        return ret;
    }
};

int main()
{
    TreeNode *root = new TreeNode(3);
    TreeNode *n1 = new TreeNode(9);
    TreeNode *n2 = new TreeNode(20);
    TreeNode *n3 = new TreeNode(15);
    TreeNode *n4 = new TreeNode(17);
    TreeNode *test = new TreeNode;
    root->left = n1;
    root->right = n2;
    n2->left = n3;
    n2->right = n4;

    Solution *s = new Solution();
    vector<vector<int>> ret = s->zigzagLevelOrder(root);
    return 0;
}
