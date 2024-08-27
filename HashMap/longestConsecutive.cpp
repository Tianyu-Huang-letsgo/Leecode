#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

using namespace std;

// 最长连续序列
class Solution
{
public:
    // 思路：将值填在hash上，对hash进行遍历，不断刷新最大值
    // 要求使用O(n)的复杂度，即不能对数组进行排序
    // 核心：难点在于时间复杂度，不能两层遍历，只能从最小值开始遍历，如何找到最小值？只要存在num-1即跳过计数，否则开始计数
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> s; // 非排序集合
        for (auto num : nums)
        {
            s.emplace(num); // 使用set去重
        }
        int longest_count = 0;
        for (auto it = s.begin(); it != s.end(); it++)
        {
            if (!s.count(*it - 1)) // 核心，碰到最小值才开始计数，能找到比它小1的数，它就不是最小值
            {
                int cnt = 1;
                int num = *it;
                while (s.count(num + 1))
                {
                    cnt++;
                    num++;
                }
                longest_count = max(longest_count, cnt);
            }
        }
        return longest_count;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> nums = {3, 2, 4};
    return 0;
}