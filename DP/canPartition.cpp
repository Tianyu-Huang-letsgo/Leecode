#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

// 分割等和子集
// 抽象为01背包问题
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0] == 0 ? true : false;
        }
        int sum = 0;
        for (auto num : nums)
        {
            sum += num;
        }
        if (sum % 2 != 0)
        {
            return false;
        }
        sum /= 2;
        vector<int> dp(sum + 1, 0); // 容量为0时最大装载价值也为0
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = sum; j >= 1; --j)
            {
                if (j >= nums[i])
                {
                    dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
                }
            }
        }
        return dp[sum] == sum;
    }
};

int main()
{
    return 0;
}