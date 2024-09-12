#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

// 98. 验证二叉搜索树
// 根本性质：左子树(最大值) < 根节点 < 右子树(最小值)
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 更优解:**根作为其左子树的上限，其右子树的下限**，一旦节点值不在合法域内，返回false
class Solution
{
public:
    bool helper(TreeNode *root, long long lower, long long upper)
    {
        if (root == nullptr)
        {
            return true;
        }
        if (root->val <= lower || root->val >= upper)
        {
            return false;
        }
        // 逆向思维：左子树值一定小于根值，右子树值一定大于根值，不断往下深度遍历即可
        return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
    }
    bool isValidBST(TreeNode *root)
    {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};

class Solution2
{
public:
    bool isValidBST(TreeNode *root)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            return true;
        }
        int val = root->val;
        dfs(root, val);
        return this->ret_;
    }

private:
    bool ret_ = true;
    // 返回root子树下最大、最小值
    pair<int, int> dfs(TreeNode *root, int val)
    {
        if (ret_ == false)
        {
            return make_pair(val, val);
        }
        if (root == nullptr)
        {
            return make_pair(val, val);
        }
        pair<int, int> leftVal = dfs(root->left, root->val);
        pair<int, int> rightVal = dfs(root->right, root->val);
        int leftMax = leftVal.first;
        int leftMin = leftVal.second;
        int rightMax = rightVal.first;
        int rightMin = rightVal.second;
        if (root->val < leftMax || root->val > rightMin)
        {
            this->ret_ = false;
        }
        // 这里是难在三个相同的数字要进行判断
        if (root->left && root->val == leftMax || root->right && root->val == rightMin)
        {
            this->ret_ = false;
        }
        return make_pair(max(root->val, rightMax), min(root->val, leftMin));
    }
};

TreeNode *genTree(vector<int> vec)
{
    if (vec.empty())
        return nullptr;

    // 创建根节点
    TreeNode *root = new TreeNode(vec[0]);
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);
    int i = 1;

    // 按层次顺序构建二叉树
    while (!nodeQueue.empty() && i < vec.size())
    {
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();

        // 处理左子节点
        if (i < vec.size() && vec[i] != INT_MIN)
        {
            node->left = new TreeNode(vec[i]);
            nodeQueue.push(node->left);
        }
        i++;

        // 处理右子节点
        if (i < vec.size() && vec[i] != INT_MIN)
        {
            node->right = new TreeNode(vec[i]);
            nodeQueue.push(node->right);
        }
        i++;
    }

    return root;
}

int main()
{
    vector<int> v = {2, 2, 2};
    TreeNode *root = genTree(v);
    Solution *s = new Solution();
    bool ret = s->isValidBST(root);
    return 0;
}