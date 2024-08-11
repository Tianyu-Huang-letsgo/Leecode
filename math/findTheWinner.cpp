#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
public:
    // 约瑟夫环问题
    int findTheWinner(int n, int k)
    {
        int x = 0; // f(1) = 0
        for (int i = 2; i <= n; i++)
        {
            x = (x + k) % i; // 从f(2) = (f(1) + k) % 2开始，状态转移方程
        }
        return ++x;    // 我们假定是从0开始的，题目要求是从1开始
    }
};

int main()
{
    return 0;
}