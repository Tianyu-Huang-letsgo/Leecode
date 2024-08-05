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

// 递归好题

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // 1. 终止条件：当越过叶节点时，直接返回null；当root等于p,q，直接返回root；（因为不可能比这个更深了，再深p和q其中一个就要没了）
        if (root == nullptr)
            return root;
        if (root == p || root == q)
            return root;

        // 2. 递归工作：左右中，涉及到后序，一定要使用后序遍历，因为遍历完左右之后已经有了想要的结果，才能在中进行处理。
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        // 3. 中的处理逻辑
        if (left != nullptr && right != nullptr)
            return root;
        if (left == nullptr && right != nullptr)
            return right;
        if (right == nullptr && left != nullptr)
            return left;
        if (right == nullptr && left == nullptr)
            return nullptr;
        return root;
    }
};

int main()
{
    Solution *s = new Solution();
    TreeNode *root = new TreeNode(3);
    TreeNode *n1 = new TreeNode(9);
    TreeNode *n2 = new TreeNode(20);
    TreeNode *n3 = new TreeNode(15);
    TreeNode *n4 = new TreeNode(17);
    root->left = n1;
    root->right = n2;
    n2->left = n3;
    n2->right = n4;
    TreeNode *ret = s->lowestCommonAncestor(root, n3, n4);
    int val = ret->val;
    return 0;
}