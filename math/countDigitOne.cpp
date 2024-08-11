#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

class Solution
{
public:
    // 计算遍历历史中每一位出现1的次数
    int countDigitOne(int n)
    {
        // 1. 初始化数据
        int cur = n % 10;
        int digit = 1; // 1,10,100...
        int high = n / 10;
        int low = 0;

        int cnt = 0;

        while (high != 0 || cur != 0) // 当前位不为0 或者 当前位不是最高位
        {
            if (cur == 0)
            {
                cnt += high * digit;
            }
            else if (cur == 1)
            {
                cnt += high * digit + low + 1;
            }
            else
            {
                cnt += (high + 1) * digit;
            }

            low += digit * cur;
            cur = high % 10;
            high /= 10;
            digit *= 10;
        }
        return cnt;
    }
};
int main()
{
    Solution* s = new Solution();
    int ret = s->countDigitOne(0);
    return 0;
}