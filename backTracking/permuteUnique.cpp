#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    // nums可包含重复数字，返回所有不重复的全排列
    // 思路：因为有重复数字，但是在当前层只要遍历过其中一个数字，当前层下的所有路径会跟其他同数字的路径重合；需要做一个层剪枝
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<bool> isSelectecd(20 + 1, 0);
        vector<int> vec;
        dfs(nums, vec, isSelectecd);
        return this->ret_;
    }

private:
    vector<vector<int>> ret_;
    void dfs(vector<int> &nums, vector<int> &vec_tmp, vector<bool> &isSelected)
    {
        if (vec_tmp.size() == nums.size())
        {
            ret_.push_back(vec_tmp);
            return;
        }
        unordered_set<int> num_set; // num_set放在外层，就是让每一层可以刷新自己的一个num_set
        for (int i = 0; i < nums.size(); i++)
        {
            if (!isSelected[i] && num_set.find(nums[i]) == num_set.end())
            {
                num_set.emplace(nums[i]); // 这个值不用回退，就是因为它就是记录当前层的数据；当遍历完当前层，就会返回上一层的num_set,是另外一个不同的容器
                vec_tmp.push_back(nums[i]);
                isSelected[i] = 1;
                dfs(nums, vec_tmp, isSelected);
                isSelected[i] = 0;
                vec_tmp.pop_back();
            }
        }
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> ret = s->permuteUnique(nums);
    return 0;
}