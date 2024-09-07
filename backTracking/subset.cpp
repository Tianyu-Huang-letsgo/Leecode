#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// 子集
// 子集问题就是一个元素是否选择的问题2^n
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        res.push_back({});
        // 遍历数组中的元素，将它们加到已存在的nums数组元素中
        // 合理：
        // 唯一性：之前存在的数组元素都是唯一的，加上此值依然唯一
        // 完整性：在想元素后添加当前num的时候，每一个添加的都是包含该num的子集
        for (auto num : nums)
        {
            int size = res.size(); // 这个值是动态变化的，所以要先记录
            for (int i = 0; i < size; ++i)
            {
                vector<int> tmp = res[i];
                tmp.push_back(num);
                res.push_back(tmp);
            }
        }
        return res;
    }
};

class Solution2
{
public:
    vector<int> t;
    vector<vector<int>> ans;

    void dfs(int cur, vector<int> &nums)
    {
        if (cur == nums.size())
        {
            ans.push_back(t); // 遍历完成了就应该放入结果
            return;
        }
        // **典型的回溯算法应用**
        // 回溯的核心：遍历序列（全集）到头，符合条件的结果就返回
        // 子集的本质：在全集中，选中某些元素（其他部分不选），就是这个集合的子集
        t.push_back(nums[cur]); // 选中当前cur元素
        dfs(cur + 1, nums);     // 递归处理下一个元素
        t.pop_back();           // 弹出当前cur元素
        dfs(cur + 1, nums);     // 不选择当前元素
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        dfs(0, nums);
        return ans;
    }
};

int main()
{
    vector<int> v = {1, 2, 3};
    Solution *s = new Solution();
    vector<vector<int>> ret = s->subsets(v);
    return 0;
}