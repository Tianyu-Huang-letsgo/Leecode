#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

class Solution
{
public:
    // 从第0阶格雷码向下推导，往下一阶就进行反转（中心对称）、拼接再分别补0补1。
    // 这样恰好能满足所有条件
    vector<int> grayCode(int n)
    {
        vector<int> ret;
        ret.push_back(0);
        int head = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = ret.size() - 1; j >= 0; j--)
            {
                ret.push_back(ret[j] + head);
            }
            head <<= 1;
        }
        return ret;
    }
};

int main()
{
    return 0;
}