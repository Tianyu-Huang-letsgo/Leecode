#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    // 使用快速排序的思路，划分为大于哨兵、等于哨兵，小于哨兵的三个部分
    // 终点就是k会落在equal的部分
    int findKthLargest(vector<int> &nums, int k)
    {
        return quickSelect(nums,k);
    }

private:
    int quickSelect(vector<int> &nums, int k)
    {
        vector<int> l;
        vector<int> eq;
        vector<int> s;
        int pivot = nums[rand() % nums.size()]; // 根据哨兵进行划分
        for (auto num : nums)
        {
            if (num < pivot)
                s.push_back(num);
            else if (num > pivot)
                l.push_back(num);
            else
                eq.push_back(num);
        }

        // 进入分区递归
        if (k <= l.size())
        {
            return quickSelect(l, k);
        }
        else if (k > l.size() + eq.size())
        {
            return quickSelect(s, k - eq.size() - l.size());
        }
        return pivot;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> vec = {3, 2, 1, 5, 6, 4};
    int ret = s->findKthLargest(vec, 2);
    return 0;
}