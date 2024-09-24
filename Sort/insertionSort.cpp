#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// 插入排序（稳定）
// 在未排序区间选择一个基准元素，将元素与其左侧已排序区间元素逐一比较大小，将元素插入到正确位置
void insertionSort(vector<int> &nums)
{
    // 假定i=0的第一个数是已经排好序的
    for (int i = 1; i < nums.size(); ++i)
    {
        int j = i - 1;
        int base = nums[i]; // 将未排序第一个数作为基准数
        while (j >= 0 && nums[j] > base)
        {
            nums[j + 1] = nums[j]; // 已排序元素进行移位
            --j;
        }
        nums[j + 1] = base;
    }
}

int main()
{
    return 0;
}