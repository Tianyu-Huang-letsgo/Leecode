#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

// 买卖股票的最佳时机
// 千万不要将问题复杂化！
class Solution
{
public:
    // 先记录dp[1] = 第一天买入第二天卖出价格
    // dp[i]:选择在第i天卖出的最大价格，选择在第i天卖出price[i-1] - min; 选择不在第i天卖出：dp[i-1]
    // 是否需要记录数组状态？
    int maxProfit(vector<int> &prices)
    {
        int p_min = prices[0];
        int ret = 0;
        for (int i = 0; i < prices.size(); ++i)
        {
            ret = max(ret, prices[i] - p_min); // 后来的减先前记录的最小值，不断刷新就好
            p_min = min(p_min, prices[i]);
        }
        return ret;
    }
};

class Solution2
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
            min = std::min(prices[i - 1], min); // 持续刷新最小值
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

    return 0;
}