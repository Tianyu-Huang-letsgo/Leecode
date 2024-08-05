#include <string>
#include <algorithm>
#include <climits>
#include <math.h>

using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        long long ret = 0;
        // 1. 消除前置空格
        int i = 0;
        bool flag = false;
        while (s[i] == ' ')
        {
            i++;
        }
        if (i >= s.size())
        {
            return 0;
        }

        // 2. 判断符号，记录标志
        if (s[i] == '-')
        {
            flag = true;
            i++;
        }
        else if (s[i] == '+')
        {
            i++;
        }

        // 3. 跳过0位
        while (s[i] == '0')
        {
            i++;
        }

        // 3. 判断字符
        // 这里还要计算位数，大于位数直接退出循环
        int cnt = 0;
        while (i < s.size())
        {
            if (s[i] < '0' || s[i] > '9')
            {
                break;
            }
            ret = 10 * ret + s[i] - '0';
            cnt++;
            if (cnt > 11)
            {
                break;
            }
            i++;
        }

        if (flag)
        {
            ret = -ret;
        }
        // int a = 2e31 - 1;
        //
        if (ret > INT_MAX || double(ret) < INT_MIN)
        {
            ret = ret > 0 ? INT_MAX : INT_MIN;
        }
        long long num_oo = pow(2, 31);

        return ret;
    }
};

int main()
{
    Solution *s = new Solution;
    int ret = s->myAtoi("  0000000000012345678");
    return 0;
}