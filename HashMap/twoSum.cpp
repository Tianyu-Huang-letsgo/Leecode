#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 两数之和
class Solution
{
public:
    // 思路：因为只会存在一个有效答案，所以不会出现两个以上相同元素构成target
    // 将出现过的数字存入hashmap，核心是要记录下标，搜索到能组成target的数则返回
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = map.find(target - nums[i]);
            if (it != map.end())
            {
                res.push_back(i);
                res.push_back(it->second);
                break;
            }
            map.insert(make_pair(nums[i], i));
        }
        return res;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> nums = {3, 2, 4};
    vector<int> res = s->twoSum(nums, 6);
    return 0;
}