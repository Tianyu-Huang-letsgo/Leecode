#include <stdio.h>
#include <iostream>

using namespace std;

class Solution
{
public:
    // 思路：不断二分下去相乘，再将结果返上来，O(logn)
    // 这种都超出时间限制了...
    double myPow(double x, int n)
    {
        bool flag = false;
        if (n == 0)
        {
            return 1;
        }
        if (n < 0)
        {
            return double(1) / dfs(x, -n);
        }
        return dfs(x, n);
    }

private:
    double dfs(double x, int n)
    {
        if (n == 1)
        {
            return x;
        }
        double lef = n % 2 == 0 ? 1 : x;
        double ret = dfs(x, n / 2) * dfs(x, n / 2) * lef;
        return ret;
    }
};

// 大佬答案：快速幂
// 将指数作为二进制数，也作为一个掩码
// 整体是x的幂数相乘，当前位置是前一个位置的平方
// 有掩码的位置需要乘以当前的累乘数
class Solution
{
public:
    double myPow(double x, int n)
    {
        if (x == 0.0)
            return 0.0; // 如果底数为0，任何非零次幂都为0
        double res = 1.0;

        // 如果指数为负，将底数取倒数，指数取正
        long long m = abs(n);
        if (n < 0)
        {
            x = 1 / x;
        }

        // 思路：以指数作为二进制的思想，每一位都是上一位累乘数的平方
        while (m > 0)
        {
            if (m & 1)
                res *= x; // 如果当前指数为奇数，则乘以当前的x
            x *= x;       // 底数自乘，准备下一次循环
            m >>= 1;      // 指数右移一位，相当于除以2
        }

        return res;
    }
};
