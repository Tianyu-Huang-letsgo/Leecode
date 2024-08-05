#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
public:
    // 核心：1. 无重复数组；2. 同一个数字可以无限重复被选取；3. 数字>=2，无负数
    // 难点：如何进行剪枝使得时间复杂度最低
    // 剪枝思路：当前值的下一个值只能是自身以及之后下标的数字，如数组[2，3，6，7];2下一个数字可以是2，3，6，7；6下一个数字只能是6，7
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> v;
        int index = 0;
        dfs(candidates, target, v, index);
        return this->ret_;
    }

private:
    vector<vector<int>> ret_;
    // 加上一个上一层下标，进行遍历
    void dfs(vector<int> &candidates, int target, vector<int> &vec_tmp, int pre_index)
    {
        // 返回条件，值凑满了
        if (target == 0)
        {
            ret_.push_back(vec_tmp);
            return;
        }
        // 剪枝核心：选取数值只能是下标及
        for (int i = pre_index; i < candidates.size(); i++)
        {
            if (target - candidates[i] >= 0)
            {
                vec_tmp.push_back(candidates[i]);
                target -= candidates[i];
                dfs(candidates, target, vec_tmp, i);
                target += candidates[i];
                vec_tmp.pop_back();
            }
        }
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> vec = {2, 3, 5};
    vector<vector<int>> ret = s->combinationSum(vec, 8);
    return 0;
}