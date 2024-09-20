#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// 169. 多数元素
class Solution
{
public:
    // **摩尔投票**：核心-保证众数任何情况下都为众数
    // 做出这种《错误的》假设不会影响结果
    int majorityElement(vector<int> &nums)
    {
        int score = 0;
        if (nums.size() == 1)
        {
            return nums[0];
        }

        int ret = nums[0]; // 众数
        for (auto num : nums)
        {
            if (score == 0)
            {
                ret = num;
            }
            if (num == ret)
            {
                ++score;
            }
            else
            {
                --score;
            }
        }
        return ret;
    }
};

int main()
{
    return 0;
}