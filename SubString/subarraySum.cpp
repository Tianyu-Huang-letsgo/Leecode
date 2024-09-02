#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

// 和为K的子数组
// 第一思路：滑动窗口
// 难点：存在负数，不是说元素越加越大
// 答案：前缀和
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> hash;
        int ret = 0;
        int sum = 0;
        hash[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (hash.find(sum - k) != hash.end())
            {
                ret += hash[sum - k];
            }
            hash[sum]++; // 前缀和哈希更新有讲究，要在ret刷新过后才能更新，因为要避免k=0的情况！
        }
        return ret;
    }
};

int main()
{
    vector<int> v = {1, 1, 1};
    Solution *s = new Solution();
    s->subarraySum(v, 2);
    return 0;
}