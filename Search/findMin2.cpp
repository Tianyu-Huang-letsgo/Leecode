#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

// 寻找旋转排序数组中的最小值
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        int pivot = nums.size() - 1;
        int ret_ind = pivot;    // 初始化为右数组的值
        while (l <= r)
        {
            int m = (l + r) >> 1;
            if (nums[m] > nums[pivot]) // 位于左数组
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
                ret_ind = m;    // 能找到右数组更小值才刷新
            }
        }
        return nums[ret_ind];
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> v = {3, 4, 5, 1, 2};
    int ret = s->findMin(v);
    return 0;
}