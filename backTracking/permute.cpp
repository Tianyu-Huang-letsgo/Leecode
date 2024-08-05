#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
public:
    // 不含重复数组，不用在当前层进行剪枝
    // 全排列需要做路径剪枝（不同层），需要isSelect[]进行记录是否在路径上选择过
    // 题目中-10 < num[i] < 10 需要做一个偏移
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<bool> isSel(21, 0);
        int cnt = 0;
        vector<int> tmp;
        dfs(nums, isSel, 0, tmp);
        return this->ret_;
    }

private:
    vector<vector<int>> ret_;
    void dfs(vector<int> &nums, vector<bool> &isSelected, int cnt, vector<int>& vec)
    {
        // 找到正确答案处理
        if (cnt == nums.size())
        {
            ret_.push_back(vec);
        }
        for (auto num : nums)
        {
            if (!isSelected[num + 10])
            {
                vec.push_back(num);
                cnt++;
                isSelected[num + 10] = 1;
                dfs(nums, isSelected, cnt, vec);
                isSelected[num + 10] = 0;
                cnt--;
                vec.pop_back();
            }
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