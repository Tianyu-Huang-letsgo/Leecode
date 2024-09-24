#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// 选择排序-每次选择《未排序区间》最小的数与《已排序区间》后一个数进行交换
void selectionSort(vector<int> &nums)
{
    // 未排序区间[i, n-1]
    // 第一个要找的就是整个数组中最小的数作为数组头
    for (int i = 0; i < nums.size() - 1; ++i)
    {
        int k = i;
        for (int j = i + 1; j < nums.size(); ++j)
        {
            if (nums[j] < nums[k])
            {
                k = j;
            }
        }
        swap(nums[i], nums[k]);
    }
}

int main()
{
    return 0;
}