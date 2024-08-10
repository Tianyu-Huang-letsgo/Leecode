#include <iostream>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        bool ret = false;
        if (n == 0)
        {
            return false;
        }
        while (n > 0)
        {
            int flag = n & 1;
            n = n >> 1;
            if (flag)
            {
                break;
            }
        }
        if (n == 0)
        {
            ret = true;
        }
        return ret;
    }
};

int main()
{

    return 0;
}