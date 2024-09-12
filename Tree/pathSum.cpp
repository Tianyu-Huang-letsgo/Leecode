#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

// 路径总和Ⅲ
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 要求：
// 1. 求路径节点值等于targetSum路径数量
// 2. 路径方向只能从父节点到子节点

// 思路：hash、前缀和
class Solution
{
public:
    int pathSum(TreeNode *root, int targetSum)
    {
        unordered_map<long, int> map;
        map[0] = 1;
        this->target_ = targetSum;
        dfs(root, 0, map);
        return this->cnt_;
    }

private:
    int cnt_ = 0;
    int target_;
    void dfs(TreeNode *root, long sum, unordered_map<long, int> hash)
    {
        if (root == nullptr)
        {
            return;
        }
        sum += root->val;
        if (hash[sum - target_] > 0)
        {
            cnt_ += hash[sum - target_];
        }
        ++hash[sum];
        dfs(root->left, sum, hash);
        dfs(root->right, sum, hash);
    }
};

// 回溯：更优，不用进行值拷贝传递
class Solution
{
    void backtrace(TreeNode *cur, int targetSum, unordered_map<long long, int> &presumset, long long presum, int &res)
    {
        if (!cur)
            return;
        presum += cur->val;
        if (presumset.count(presum - targetSum))
            res += presumset[presum - targetSum];
        presumset[presum]++;
        backtrace(cur->left, targetSum, presumset, presum, res);
        backtrace(cur->right, targetSum, presumset, presum, res);
        presumset[presum]--; // 精髓：在回溯的时候磨灭掉这个节点的痕迹
    }

public:
    int pathSum(TreeNode *root, int targetSum)
    {
        unordered_map<long long, int> presumset{{0, 1}};
        long long presum = 0;
        int res = 0;
        backtrace(root, targetSum, presumset, presum, res);
        return res;
    }
};

int main()
{
    return 0;
}