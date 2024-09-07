#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 寻找数组的中心下标
class Solution
{
public:
    // 思路：直接遍历
    // 难点：指针不能回头
    // 完整遍历应该是一个不错的选择
    int pivotIndex(vector<int> &nums)
    {
        // int left = 0, right = nums.size() - 1;
        // int mid = left + (right - left) >> 1;
        int index = 0;
        int cnt = nums.size();
        int sum_l = 0;
        int sum_r = sum(1, cnt - 1, nums);
        int ret = -1;

        while (index < cnt)
        {
            int cur_num = nums[index];
            if (sum_l == sum_r)
            {
                ret = index;
                break;
            }
            else
            {
                sum_l += cur_num;
                sum_r = index < cnt - 1 ? sum_r - nums[index + 1] : sum_r;
                index++;
            }
        }
        return ret;
    }

    int sum(int l, int r, vector<int> &v)
    {
        int ret = 0;
        for (int i = l; i <= r; i++)
        {
            ret += v[i];
        }
        return ret;
    }
};

int main()
{
    vector<int> v = {1, 7, 3, 6, 5, 6};
    Solution *s = new Solution();
    int ret = s->pivotIndex(v);
    return 0;
}