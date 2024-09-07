#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// 全排列
class Solution
{
public:
    // 不含重复数组，不用在当前层进行剪枝
    // 全排列需要做路径剪枝（不同层），需要isSelect[]进行记录是否在路径上选择过
    // 题目中-10 < num[i] < 10 需要做一个偏移
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<bool> isSelect(21, 0); // nums数组范围是-10 ~ 10
        vector<int> tmp;
        dfs(nums, 0, tmp, isSelect);
        return this->ret_;
    }

private:
    vector<vector<int>> ret_;
    void dfs(const vector<int> &nums, int cnt, vector<int> &cur, vector<bool> &isSelect)
    {
        if (cnt == nums.size())
        {
            this->ret_.push_back(cur);
        }
        for (int i = 0; i < nums.size(); i++) // 这里如果单纯是遍历元素，没利用到索引的话，使用auto num : nums效率会更高
        {
            if (isSelect[nums[i] + 10]) // 剪枝重复选取
            {
                continue;
            }
            isSelect[nums[i] + 10] = 1;
            cur.push_back(nums[i]);
            ++cnt;
            dfs(nums, cnt, cur, isSelect);
            --cnt;
            cur.pop_back();
            isSelect[nums[i] + 10] = 0;
        }
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};
    Solution *s = new Solution();
    vector<vector<int>> ret = s->permute(nums);
    return 0;
}