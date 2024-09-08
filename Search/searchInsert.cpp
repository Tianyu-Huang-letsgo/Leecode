#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
// 搜索插入位置
// 条件：nums为无重复元素的升序排列数组
// 目标：找到大于等于这个值的位置
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        int res = nums.size(); // 插入值也需要进行初始化,注意，这里要放在最右边
        while (l <= r)
        {
            int m = (l + r) >> 1;
            if (nums[m] < target)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
                res = m; // 找到大于等于target的值才进行刷新
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}