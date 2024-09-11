#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

// 零钱兑换
// 定义动态表dp[i]:金额i下使用的最少硬币数
// coin:coins,min(dp[i - coin] + 1, dp[i])
// 与完全平方数是完全一样的思路，对金额进行完全遍历
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0)
        {
            return 0;
        }
        vector<int> dp(amount + 1, 1e4 + 10);
        dp[0] = 0; // 核心
        for (int i = 1; i <= amount; ++i)
        {
            for (auto coin : coins) // 遍历选项，搜索当前状态是否能从上一个状态转移得到
            {
                if (coin <= i)
                {
                    dp[i] = min(dp[i - coin] + 1, dp[i]); // 如果i-coin这个值已经被赋予，那么是可以进行转移的
                }
            }
        }
        return dp[amount] == 1e4 + 10 ? -1 : dp[amount];
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> v = {1, 2, 5};
    int ret = s->coinChange(v, 11);
    return 0;
}