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
    // 难点：如何进行分层
    // 解题思路：每次遍历完一层，添加到数组的一定只能是下一层，故先记录当前层尺寸即可
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> que;
        vector<vector<int>> ret;
        if (root != nullptr)
        {
            que.push(root);
        }
        while (!que.empty())
        {
            vector<int> vec_tmp;
            int cnt = que.size();
            for (int i = 0; i < cnt; i++)
            {
                TreeNode *top = que.front();
                que.pop();
                vec_tmp.push_back(top->val);
                if (top->left != nullptr)
                    que.push(top->left);
                if (top->right != nullptr)
                    que.push(top->right);
            }
            ret.push_back(vec_tmp);
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
    vector<vector<int>> ret = s->levelOrder(root);
    return 0;
}