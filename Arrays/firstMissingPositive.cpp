#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

// 缺失的第一个正数
// 核心：N个数，如果1~N都出现了，那么最小值就是N+1，否则答案就在数组中
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            // 数据预处理:将所有负数和0转换为一个做一个清理
            // 将数组中所有数转化为正数
            if (nums[i] <= 0)
                nums[i] = nums.size() + 1;
        }
        // 哈希遍历
        for (int i = 0; i < nums.size(); i++)
        {
            if (abs(nums[i]) <= nums.size() && nums[abs(nums[i]) - 1] > 0) // 注意：被标记过的不能重复标记，否则符号位又要变化；比数组范围大的也不用标记，最终目的是想看1~N的范围那个数没被标记
            {
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1]; // 一个数字符号位变化了，根本信息还是在的
            }
        }
        int ret = nums.size() + 1;
        // 第一个未被标记的数就是答案
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                ret = i + 1;
                break;
            }
        }
        return ret;
    }
};
int main()
{
    vector<int> v = {1, 1};
    Solution *s = new Solution();
    int ret = s->firstMissingPositive(v);
    return 0;
}