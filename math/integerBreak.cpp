#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

class Solution
{
public:
    // 3是性价比最高的累乘基底数
    int integerBreak(int n)
    {
        int ret;
        int cnt = n / 3;
        int lef = n % 3;
        if (cnt == 0 || lef == 0 && cnt == 1)
        {
            return n - 1;
        }
        // 如果余1，要拿一个3拆成2+1
        if (lef == 1)
        {
            ret = pow(3, cnt - 1) * 4;
        }
        if (lef == 0)
        {
            ret = pow(3, cnt);
        }
        // 如果余2或0，直接相乘
        if (lef == 2)
        {
            ret = pow(3, cnt) * 2;
        }
        return ret;
    }
};

int main()
{

    return 0;
}