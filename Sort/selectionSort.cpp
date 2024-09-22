#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// 选择排序-每次选择《未排序区间》最小的数与《排序区间》末端进行交换
void selectionSort(vector<int> &nums)
{
    int n = nums.size();
    // 未排序区间[i, n-1]
    for (int i = 0; i < n - 1; ++i)
    {
        int k = i;
        for (int j = i + 1; j < n - 1; ++j)
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