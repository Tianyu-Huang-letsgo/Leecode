#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

#include <vector>
#include <algorithm>

class Solution
{
public:
    int rob(std::vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        return std::max(robRange(nums, 0, nums.size() - 2), robRange(nums, 1, nums.size() - 1));
    }

private:
    int robRange(const std::vector<int> &nums, int start, int end)
    {
        int cur = 0, pre = 0;
        for (int i = start; i <= end; ++i)
        {
            int temp = std::max(pre + nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};

int main()
{
    return 0;
}
