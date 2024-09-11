#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 乘积的最大子数组
// 关键：由于存在负数(负相关直线):那么会导致最大的变最小的，最小的变最大的，因此还需要维护当前最小值min
// 思路：当前元素想要跟前面元素连成子数组，必须先包含其前一个元素，也就是之前元素对当前值是否有增益
//
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int imax = 1; // 一定包含当前值的最大值
        int imin = 1; // 一定包含当前值的最小值，这个值是核心，一遇到负数就可以转化成最大值了
        int max_num = INT_MIN;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] < 0)
            {
                int tmp = imin;
                imin = imax;
                imax = tmp;
            }
            imax = max(nums[i], imax * nums[i]);
            imin = min(nums[i], imin * nums[i]);
            max_num = max(max_num, imax);
        }
        return max_num;
    };
};

int main()
{
    vector<int> v = {2, 3, -2, 4};
    Solution *s = new Solution();
    int ret = s->maxProduct(v);
    return 0;
}
