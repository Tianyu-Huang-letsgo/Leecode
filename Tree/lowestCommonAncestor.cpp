#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

// 二叉树的最近公共祖先
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 思路：
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // 1. 终止条件：当越过叶节点时，直接返回null；当root等于p,q，直接返回root；（因为不可能比这个更深了，再深p和q其中一个就要没了）
        if (root == nullptr)
            return root;
        if (root == p || root == q) // 核心1：找到该值即开始返回
            return root;

        // 2. 递归工作：左右中，涉及到后续，一定要使用后续遍历。
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        // 3. 中的处理逻辑
        if (left != nullptr && right != nullptr) // 只有当左子树找到了，右子树也找到了，root才是最近公共祖先，将自身不断向上返回
            return root;
        if (left == nullptr && right != nullptr) // 右子树找到了，向上返回
            return right;
        if (right == nullptr && left != nullptr) // 左子树找到了，向上返回
            return left;
        if (right == nullptr && left == nullptr) // 左右都没找到
            return nullptr;
        return root;
    }
};

int main()
{
    return 0;
}