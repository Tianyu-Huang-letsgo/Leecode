#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

// 114.二叉树展开为链表
// 展开后的链表应与先序遍历顺序相同
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 右子树 = 左子树 + 右子树
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        flatten(root->left);
        flatten(root->right);
        TreeNode *l = root->left;
        TreeNode *r = root->right;
        // 如果左子树非空，记录右子树根节点，将左子树移到右子树，右子树接到左子树末端，根节点左子树设为null值
        // 顺序不能搞混
        if (l)
        {
            root->right = l;
            while (l->right)
            {
                l = l->right;
            }
            l->right = r;
            root->right = root->left;
            root->left = nullptr;
        }
    }
};

int main()
{
    return 0;
}