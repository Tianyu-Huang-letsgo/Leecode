#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // 先记录dp[1] = 第一天买入第二天卖出价格
    // dp[i]:选择在第i天卖出的最大价格，选择在第i天卖出price[i-1] - min; 选择不在第i天卖出：dp[i-1]
    // 是否需要记录数组状态？
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> dp(n);
        if (n < 2)
        {
            return 0;
        }
        dp[0] = 0;
        int min = prices[0];
        for (int i = 1; i < n; i++)
        {
            min = prices[i - 1] < min ? prices[i - 1] : min;
            if (prices[i] > min)
            {
                dp[i] = max(dp[i - 1], prices[i] - min);
            }
            else
            {
                dp[i] = dp[i - 1];
            }
        }
        return dp[n - 1];
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> v = {2, 4, 1};
    int ret = s->maxProfit(v);
    return 0;
}
