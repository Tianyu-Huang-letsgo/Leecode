#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// 108. 将有序数组转换为二叉搜索树
// 将升序数组转化为一棵平衡二叉搜索树
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
    // 将中间位置左边作为根节点
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return makeTree(nums, 0, nums.size() - 1);
    }

private:
    TreeNode *makeTree(const vector<int> &nums, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
        int mid = (left + right) >> 1;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = makeTree(nums, left, mid - 1);
        node->right = makeTree(nums, mid + 1, right);
        return node;
    }
};

int main()
{
    vector<int> v = {-10, -3, 0, 5, 9};
    Solution *s = new Solution();
    TreeNode *node = s->sortedArrayToBST(v);
    return 0;
}