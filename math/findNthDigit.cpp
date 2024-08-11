#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    /*
    概念：
        数位：101112中的每一位，记为n,n从1开始
        数字：10，11，12，记为num
        位数：10的位数是2，100的位数是3（几位数）,记为digit
        每个digit位的起始数字记为start(1,10,100)
        每个位数拥有的数字count = 9 * start * digit
    */
    int findNthDigit(int n)
    {
        int digit = 1;
        long start = 1;
        long count = 9;
        // 1. 计算n所在数字的位数
        while (n > count)
        {
            n -= count;
            ++digit;
            start *= 10;
            count = 9 * start * digit;
        }

        // 递减后，n从所在位数开始计数：1，2，3，...，n
        // 2. 计算在当前位数的第几个num
        long num = start + (n - 1) / digit; // 这里因为是从start加起的，所以即便满了位数，也要先-1再除以digit

        // 3. 计算num的第几位(从0开始)
        long i = (n - 1) % digit;

        string str = to_string(num);
        return str[i] - '0';
    }
};

int main()
{

    return 0;
}