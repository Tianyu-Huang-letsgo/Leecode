#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

// 轮转数组
class Solution
{
public:
    // 三次翻转实现轮转
    void rotate(vector<int> &nums, int k)
    {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
int main()
{
    vector<int> v = {-1, -100, 3, 99};
    Solution *s = new Solution();
    s->rotate(v, 2);
    return 0;
}