#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // 每次可以爬1阶或2阶，有多少种方法
    int climbStairs(int n)
    {
        // 定义dp表，第i,这里不用记录上次跳了多少
        vector<int> dp(n + 1, 0);
        if (n <= 2)
        {
            return n;
        }
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main()
{
    Solution *s = new Solution();
    int i = s->climbStairs(1);
    return 0;
}