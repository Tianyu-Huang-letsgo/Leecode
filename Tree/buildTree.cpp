#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

// 105.从前序与中序遍历序列构造二叉树
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
        unordered_map<int, int> map;
        // 创建一个中序元素，索引映射表，输入中序元素，返回中序索引
        for (int i = 0; i < inorder.size(); i++)
        {
            map.insert(make_pair(inorder[i], i));
        }
        // int m = map[preorder[0]];
        TreeNode *root = dfs(preorder, map, 0, 0, inorder.size() - 1);
        return root;
    }

private:
    // i是preorder中的下标，l,r是inorder中的下标
    TreeNode *dfs(vector<int> &preorder, unordered_map<int, int> &inorder_map, int i, int l, int r)
    {
        if (l > r)
        {
            return nullptr;
        }
        int val = preorder[i];
        TreeNode *root = new TreeNode(val);
        int m = inorder_map[val]; // 只有知道了中序中根节点，左子节点的位置，才能推算preorder中右子节点的位置
        root->left = dfs(preorder, inorder_map, i + 1, l, m - 1);
        root->right = dfs(preorder, inorder_map, i + 1 + (m - l), m + 1, r); // 知道左子树长度，才能推算preorder中的右子树根节点索引
        return root;
    }
};

int main()
{
    return 0;
}
