#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// 数组中第K个最大元素
// 要求时间复杂度为O(n)，即不能对数组进行排序
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        return quickSelect(nums, k);
    }

private:
    int quickSelect(vector<int> &nums, int k) // 进入递归，每一层状态是当前容器与第k个最大值
    {
        int pivot = nums[rand() % nums.size()]; // 哨兵分界
        vector<int> l;
        vector<int> eq;
        vector<int> s;
        // 大中小分类
        for (auto num : nums)
        {
            if (num > pivot)
            {
                l.push_back(num);
            }
            else if (num < pivot)
            {
                s.push_back(num);
            }
            else
            {
                eq.push_back(num);
            }
        }
        if (k <= l.size()) // 每一个容器都是无序的，位于l，s容器都要进容器内部递归
        {
            return quickSelect(l, k);
        }
        else if (k > l.size() + eq.size())
        {
            return quickSelect(s, k - l.size() - eq.size());
        }
        return pivot;
    }
};

int main()
{
    vector<int> v = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    Solution *s = new Solution();
    int ret = s->findKthLargest(v, 4);
    return 0;
}