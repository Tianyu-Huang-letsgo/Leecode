#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    // 多数元素：一个计数问题
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int half = n / 2;
        unordered_map<int, int> map;
        int ret;
        for (int num : nums)
        {
            map[num]++;
            if (map[num] > half)
            {
                ret = num;
                break;
            }
        }
        return ret;
    }

    // 最优解：摩尔投票
    // 设定x为众数：如果x是众数，被其他数抵消是不亏的；如果x不是众数，其他数抵消那更是不亏。
    int majorityElement(vector<int> &nums)
    {
        int x = 0, votes = 0;
        for (int num : nums)
        {
            if (votes == 0) // 分没有了，要重新设定众数
                x = num;
            votes += num == x ? 1 : -1;
        }
        return x;
    }
};

int main()
{

    return 0;
}