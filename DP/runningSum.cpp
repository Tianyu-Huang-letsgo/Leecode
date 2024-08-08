#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        // 当前值等于当前值加上上一个值
        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] = nums[i - 1] + nums[i];
        }
        return nums;
    }
};

int main()
{
    return 0;
}
