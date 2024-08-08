#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // 非常类似有约束条件的爬楼问题
    // dp[i]: 前i间房屋能盗取到的最大值
    // dp[i] 盗取第i间->只能从dp[i-2]转移过来；不盗取第i间->从dp[i-1]转移过来
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        if (n < 2)
        {
            return dp[0];
        }
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[n - 1];
    }
};

int main()
{
    return 0;
}
