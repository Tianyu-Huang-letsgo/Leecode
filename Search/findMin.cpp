#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
    // 思路：二分查找一个下标
    // 原数组是升序，经过旋转后，可能会出现降序，这个降序的位置就是答案
    // 难点：遇到重复数字
public:
    int findMin(vector<int> &nums)
    {
        // 将nums拆分为左数组，右数组，两端分别递增。最右端作为基准值，大于最右端必为左数组，小于最右端必为右数组
        // 难点：等于最右端，将最右端干掉，刷新左右数组尺寸
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] > nums[r]) // mid必为左数组，不需要左数组，目标是找到右数组的第一个值
            {
                l = mid + 1;
            }
            else if (nums[mid] < nums[r])
            {
                r = mid;
            }
            else // 当nums[r] == nums[mid], 为保证左数组所有元素大于右数组所有元素，刷新右数组边界
            {
                r--;
            }
        }
        return nums[l];
    }
};

int main()
{
    vector<int> v = {3, 1, 3, 3};
    Solution *s = new Solution();
    int res = s->findMin(v);
    return 0;
}