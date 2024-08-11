#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
public:
    // 踩坑：1. 元素中可能有零的存在; 2. nums.length >= 2
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int mul = 1;
        int zero_cnt = 0;
        for (auto num : nums)
        {
            if (num == 0)
            {
                zero_cnt++;
                continue;
            }
            mul *= num;
        }
        vector<int> ret(nums.size(), 0);
        if (zero_cnt >= 2)
        {
            return ret;
        }
        if (zero_cnt == 0)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                ret[i] = mul / nums[i];
            }
        }
        if (zero_cnt == 1)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == 0)
                {
                    ret[i] = mul;
                }
            }
        }

        return ret;
    }
};

int main()
{

    return 0;
}