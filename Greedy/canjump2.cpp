#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// 跳跃游戏Ⅱ
// 题目保证能跳到终点
// 返回达到终点最小跳跃次数
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int rightmost = 0;
        int end = 0;
        int ans = 0;
        // 注意，这里最后一步不用遍历了，它是从别人跳到它的，它自己不用跳
        for (int i = 0; i < nums.size() - 1; i++)
        {
            rightmost = max(rightmost, nums[i] + i); // 奥妙就在这里的rightmost刷新，每一步是一个范围，这些范围内有一个最远的距离表示为rightmost
            if (i == end)                            // 到达当前最远距离后，刷新步数
            {
                end = rightmost; // 如果这里的rightmost已经超过了边界，将不会有下一步
                ans++;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}