#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // 贪心思路：所有的上涨交易日都买入，所有的下降交易日都卖出（不承受一点损失）
    // 不同点：可以多次买入卖出
    int maxProfit(vector<int> &prices)
    {
        int ret = 0;
        int n = prices.size();
        if (n == 1)
        {
            return 0;
        }
        for (int i = 1; i < n; ++i)
        {
            if (prices[i] > prices[i - 1])
            {
                ret += prices[i] - prices[i - 1];
            }
        }
        return ret;
    }
};

int main()
{
    return 0;
}