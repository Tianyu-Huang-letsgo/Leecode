#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

// 翻转二叉树
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
    TreeNode *invertTree(TreeNode *root)
    {
        dfs(root);
        return root;
    }

private:
    // 思路：只要节点不是叶子节点，都对其进行翻转
    // 这里使用了后序遍历，先序是一样的，先对根节点进行交换，再往子树里进行操作
    void dfs(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        dfs(root->left);
        dfs(root->right);
        TreeNode *tmp = root->right;
        root->right = root->left;
        root->left = tmp;
    }
};

int main()
{
    return 0;
}