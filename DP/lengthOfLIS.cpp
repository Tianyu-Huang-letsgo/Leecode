#include <vector>
#include <algorithm>

class Solution
{
public:
    // K神题解：dp[i]表示以nums[i]为结尾的最场子序列长度，注意，是一定包括num[i]的子字符串序列！！这样才能将问题具体化,一定接上你下一个才能跟你进行比较
    // 为什么要做双层循环？因为i要遍历　自己能接在之前的哪个已经有的子字符串后面，且接在哪个后面会最长！
    int lengthOfLIS(std::vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }

        std::vector<int> dp(nums.size(), 1);
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }

        return *std::max_element(dp.begin(), dp.end());
    }
};

int main()
{
    Solution *s = new Solution();
    std::vector<int> v = {1, 3, 6, 7, 9, 4, 10, 5, 6};
    int ret = s->lengthOfLIS(v);
    return 0;
}
