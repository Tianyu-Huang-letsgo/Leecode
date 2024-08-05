#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution2
{
public:
    
    // 与组合总和Ⅰ不同：数组中有重复数字，且candidates中的每个数字在每个组合中只能使用一次，即不能重复使用
    // 难点：解集不能包含重复的组合
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
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
        // 剪枝核心：选取数值只能是该下标以后的值 && 之前出现过的值都不能选取了
        /*
        这里出现了理解错误！！！这样防止的只是同一层递归的相同元素，不同层的是会进行刷新的，就比如[1，2，7, 6, 1, 5]，target = 8；选择了[1,2,5],依然能选择[2,1,5],因为这里的1一个位于第一层，一个位于第二层！！！
        */
        unordered_set<int> num_set;
        for (int i = pre_index; i < candidates.size(); i++)
        {
            if (target - candidates[i] >= 0 && num_set.find(candidates[i]) == num_set.end())
            {
                num_set.emplace(candidates[i]);
                vec_tmp.push_back(candidates[i]);
                target -= candidates[i];
                dfs(candidates, target, vec_tmp, i + 1);
                target += candidates[i];
                vec_tmp.pop_back();
            }
        }
    }
};

class Solution
{
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates, int target)
    {
        std::vector<int> currentCombination;
        std::vector<std::vector<int>> result;
        // 题目明确表明1 <= candidates.length <= 100，使用排序也是常数复杂度
        std::sort(candidates.begin(), candidates.end()); // 排序以方便处理重复元素
        dfs(candidates, target, 0, currentCombination, result);
        return result;
    }

private:
    void dfs(const std::vector<int> &candidates, int target, int start, std::vector<int> &currentCombination, std::vector<std::vector<int>> &result)
    {
        if (target == 0)
        {
            result.push_back(currentCombination);
            return;
        }

        for (int i = start; i < candidates.size(); i++)
        {
            if (candidates[i] > target)
                break; // 如果当前数字已经大于target，后面的数字也不会满足条件；直接跳出循环（即返回上一层）
            if (i > start && candidates[i] == candidates[i - 1])
                continue; // 跳过当前层的重复元素,

            currentCombination.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1, currentCombination, result); // 注意这里是 i + 1，不重复使用同一元素
            currentCombination.pop_back();
        }
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> vec = {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> ret = s->combinationSum2(vec, 8);
    return 0;
}