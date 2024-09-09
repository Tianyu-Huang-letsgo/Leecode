#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

// 跳跃游戏
// 贪心思路：每次都跳最大的格数，跳跃中断才换小的步数
// 不断拓宽最右边界，最右边界能越过数组边界说明有解
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int rightmost = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i <= rightmost)
            {
                rightmost = max(rightmost, i + nums[i]);
                if (rightmost >= n - 1)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}