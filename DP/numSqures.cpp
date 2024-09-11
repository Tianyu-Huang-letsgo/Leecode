#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

// 完全平方数
// 返回和为n的完全平方数的最少数量
class Solution
{
public:
    // dp表含义----f[n]：正数n的完全平方数最少数量
    // 状态转移：n可以由(n- j^2) + j^2转移而来，j是其方小于n的正整数
    int numSquares(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 0; // 初始化dp[0] = 0的原因：当自身就是一个完全平方数，那最少的平方和个数就是1
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = INT_MAX;
            for (int j = 1; j * j <= i; ++j) // 与零钱兑换一样，当前状态都需要遍历可以从之前的哪个状态进行转移得到
            {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};

int main()
{
    return 0;
}