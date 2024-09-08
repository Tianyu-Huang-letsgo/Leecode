#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

// 搜索旋转排序数组
// nums中每个数组都是独一无二
// 标准左右数组划分，左数组大于等于右数组，nums[nums.size() - 1]
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int pivot = nums.size() - 1;
        int l = 0, r = nums.size() - 1;
        int res = -1;
        // 1. 先搜索数组最小值索引
        int s_ind = pivot;
        while (l <= r)
        {
            int m = (l + r) >> 1;
            if (nums[m] < nums[pivot]) // 位于右数组
            {
                r = m - 1;
                s_ind = m;
            }
            else // 位于左数组
            {
                l = m + 1;
            }
        }
        if (s_ind != 0 && target > nums[s_ind - 1] || target < nums[s_ind])
        {
            return -1;
        }
        if (target <= nums[pivot])
        {
            res = binSearch(nums, s_ind, pivot, target);
        }
        else
        {
            res = binSearch(nums, 0, s_ind - 1, target);
        }
        return res;
    }

private:
    int binSearch(const vector<int> &nums, int l, int r, int target)
    {
        int ret = -1;
        while (l <= r)
        {
            int m = (l + r) >> 1;
            if (nums[m] == target)
            {
                ret = m;
                break;
            }
            else if (nums[m] > target)
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        return ret;
    }
};

int main()
{
    vector<int> v = {4, 5, 6, 7, 0, 1, 2};
    Solution *s = new Solution();
    int ret = s->search(v, 3);
    return 0;
}