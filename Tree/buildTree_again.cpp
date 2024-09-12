#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>

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
    // 先序表作用：找到根节点
    // 中序表作用：划定子树节点范围（最左叶子节点到最右叶子节点）
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> inorder_map;
        for (int i = 0; i < inorder.size(); ++i)
        {
            inorder_map[inorder[i]] = i; // 建立中序映射表，找中序表下标
        }
        return dfs(preorder, inorder_map, 0, 0, inorder.size() - 1);
    }

private:
    // i是preorder中的下标，l,r是inorder中的下标
    TreeNode *dfs(vector<int> &preorder, unordered_map<int, int> &inorder_map, int i, int l, int r)
    {
        if (l > r) // 中序树作用：判断越界
        {
            return nullptr;
        }
        int rootVal = preorder[i];
        TreeNode *root = new TreeNode(rootVal);
        int m = inorder_map[rootVal];
        root->left = dfs(preorder, inorder_map, i + 1, l, m - 1);
        root->right = dfs(preorder, inorder_map, i + 1 + (m - l), m + 1, r);
        return root;
    }
};

int main()
{
    return 0;
}