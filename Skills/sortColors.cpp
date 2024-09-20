#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

// 75. 颜色分类
// 特点：只有0，1，2三个数字属性
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        // 采用对撞双指针指向应该交换0/2的位置
        // mid负责对数组进行遍历
        int l = 0, mid = 0, r = nums.size() - 1;
        while (mid <= r)
        {
            if (nums[mid] == 0)
            {
                swap(nums[mid], nums[l++]);
            }
            if (nums[mid] == 2)
            {
                swap(nums[mid], nums[r--]);
            }
            else // 这里是核心，如果将0换到mid位置上，需要再进行一次判断交换（mid就先不向后）
            {
                ++mid; // mid不是所有交换后情况都能向后遍历
            }
        }
    }
};

int main()
{
    return 0;
}