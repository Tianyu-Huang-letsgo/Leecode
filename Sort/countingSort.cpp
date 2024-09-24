#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

// 计数排序
// 缺点：占用空间大（涵盖最小值到最大值），当nums.size() > 10*maxNum，可以使用
void countSort(vector<int> &nums)
{
    if (nums.empty())
        return;
    // 1. 寻找最大值(如果有负数还需要记录最小值进行移位操作)
    int maxNum = *max_element(nums.begin(), nums.end());
    vector<int> count(maxNum + 1, 0); // 计数数组以元素作为下标，计数作为值;以0作为初始化值是必要条件

    // 2. 计数统计
    for (auto num : nums)
    {
        count[num]++;
    }

    // 3. 计算前缀和
    for (int i = 0; i < count.size(); ++i)
    {
        count[i + 1] += count[i];
    }

    // 4. 遍历元素，放置在正确位置
    vector<int> tmp(nums.size());
    // 这里前缀和是元素计数产生的，表示的就是当前值和小于当前值的值计数和，这个数和下标是强相关的
    for (int i = tmp.size() - 1; i >= 0; --i) // 倒序遍历以保证排序数据的稳定性(本该在相对后面的元素就应该放在靠后位置)
    {
        int num = nums[i];
        tmp[count[num] - 1] = num;
        --count[num];
    }
    nums = tmp;
}

int main()
{
    return 0;
}