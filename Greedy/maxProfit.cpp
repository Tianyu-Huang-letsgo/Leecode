#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
public:
    // 难题，不能只用dp的思维方式进行思考，要从实际出发
    // 贪心思路：所有的上涨交易日都买入，所有的下降交易日都卖出
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