#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// 二叉树的直径
// 定义：指任意两个节点之间最长路径的长度
// 转换：就是找到一个节点，其左子树深度+右子树深度最大
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
    int diameterOfBinaryTree(TreeNode *root)
    {
        dfs(root, 0);
        return this->maxans_;
    }

private:
    int maxans_ = 0;
    int dfs(TreeNode *root, int dep)
    {
        if (root == nullptr)
        {
            return dep - 1;
        }
        int l = dfs(root->left, dep + 1);
        int r = dfs(root->right, dep + 1);
        maxans_ = max(maxans_, l + r - 2 * dep); // 将两侧深度转化为直径
        return max(l, r);
    }
};

int main()
{
    return 0;
}