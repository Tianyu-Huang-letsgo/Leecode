#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

// 希尔排序-插入排序改进版（不稳定）
void shellInsert(vector<int> &nums, int gap)
{
    for (int i = gap; i < nums.size(); ++i)
    {
        int base = nums[i];
        int j = i - gap;
        while (j >= 0 && nums[j] > base)
        {
            nums[j + gap] = nums[j];
            j -= gap;
        }
        nums[j + gap] = base;
    }
}

void shellSort(vector<int> &nums)
{
    int gap = nums.size();
    while (gap > 1)
    {
        gap /= 2;
        shellInsert(nums, gap); // 最后一次插排gap = 1，会进行一次一摸一样的插入排序
    }
}

int main()
{
    vector<int> nums = {5, 19, 4, 2, 6, 8, 4, 3, 12, 99};
    shellSort(nums);
    return 0;
}