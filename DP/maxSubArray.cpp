#include <vector>
#include <algorithm> // For std::max

class Solution
{
public:
    // （思路反转）将连续子数和作为sum，sum > 0表示《sum对当前数字num有增益》，sum<=0表示sum对当前数字num无增益，需要将sum重置为num（无论num正负与否，数值大小）
    // 不断刷新最大连续数组作为答案
    int maxSubArray(std::vector<int> &nums)
    {
        int ret = nums[0];
        int sum = 0;
        for (auto num : nums)
        {
            if (sum > 0) // sum存在增益(不算当前num时)
            {
                sum += num;
            }
            else // 将连续数组左边界放到num上
            {
                sum = num;
            }
            ret = std::max(ret, sum); // 奇妙的正数增益，只要我之前存在增益，就一定能连起来！
        }
        return ret;
    }
};
