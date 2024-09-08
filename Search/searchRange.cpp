#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// 在排序数组中查找元素的第一个和最后一个位置
// nums[i] == target, nums[i-1] </!+ target, num[j] == target, nums[j+1] >/!= target;
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int i = -1, j = -1;
        int l = 0, r = nums.size() - 1;
        bool flag = false;
        while (l <= r)
        {
            int m = (l + r) >> 1;
            if (nums[m] < target)
            {
                l = m + 1;
            }
            else if (nums[m] > target)
            {
                r = m - 1;
            }
            else // 如果找到了target值，m左侧区域寻找i值，m右侧区域寻找j值
            {
                flag = true;
                i = m;
                j = m;
                break;
            }
        }
        if (!flag)
        {
            return vector<int>({-1, -1});
        }
        // 找左边界,先刷新l,r
        l = 0, r = i;
        while (l <= r)
        {
            int m = (l + r) >> 1;
            if (nums[m] < target)
            {
                l = m + 1;
                i = l;
            }
            else
            {
                i = m;
                r = m - 1;
            }
        }
        // 找右边界，刷新lr
        l = j, r = nums.size() - 1;
        while (l <= r)
        {
            int m = (l + r) >> 1;
            if (nums[m] > target)
            {
                r = m - 1;
                j = r;
            }
            else
            {
                j = m;
                l = m + 1;
            }
        }
        return vector<int>({i, j});
    }
};

// 更优、更清晰解法
class Solution2
{
public:
    int binarySearch(vector<int> &nums, int target, bool lower)
    {
        int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
        while (left <= right)
        {
            int mid = (left + right) / 2;
            // 思路： 明确要找的值关系是什么（第一个比target大的，还是等于也算上）
            if (nums[mid] > target || (lower && nums[mid] >= target)) // true/false的作用是选择判断条件
            {
                right = mid - 1;
                ans = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int leftIdx = binarySearch(nums, target, true);       // 找到第一个target值
        int rightIdx = binarySearch(nums, target, false) - 1; // 找第一个比target大的值
        if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target)
        {
            return vector<int>{leftIdx, rightIdx};
        }
        return vector<int>{-1, -1};
    }
};

int main()
{
    vector<int> v = {2, 2};
    Solution *s = new Solution();
    vector<int> ret = s->searchRange(v, 2);
    return 0;
}