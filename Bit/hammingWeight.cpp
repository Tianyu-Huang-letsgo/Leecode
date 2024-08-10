#include <iostream>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    // 不断模2记录余数
    int hammingWeight(int n)
    {
        int ret = 0;
        while(n!=0)
        {
            ret += n % 2;
            n /= 2;
        }
        return ret;
    }
};

int main()
{

    return 0;
}