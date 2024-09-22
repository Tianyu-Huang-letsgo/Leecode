#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

// 快速排序-将小于基准数的元素移到其左侧，大于基准数的元素移到右侧

int partition(vector<int> &nums, int left, int right)
{
    int i = left, j = right;
    while (i < j)
    {
        while (i < j && nums[j] >= nums[left])
        {
            --j;
        }
        while (i < j && nums[i] <= nums[left])
        {
            ++i;
        }
        swap(nums[i], nums[j]);
    }
    swap(nums[left], nums[i]); // 关于交换nums[i] 与 nums[left]:只要nums[i]与nums[j]进行过交换，nums[i]肯定小于等于nums[left]
    return left;
}

void quickSort(vector<int> &nums, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int pivot = partition(nums, left, right); // 如果在递归中每一次pivot都被交换到最右端，递归深度就是n
    quickSort(nums, left, pivot - 1);
    quickSort(nums, pivot + 1, right);
}

// 尾递归优化：
/*减少最大递归深度：通过总是先递归较小的子数组，最大递归深度理论上可以降低到O(logn)。
减少栈空间使用：由于递归深度减少，所需的栈空间也相应减少，这对于处理大数据集特别有用。*/
void quickSort_optim(vector<int> &nums, int left, int right)
{
    while (left < right)
    {
        int pivot = partition(nums, left, right);
        if (pivot - left < right - pivot)
        {
            quickSort_optim(nums, left, pivot - 1);
            left = pivot + 1;
        }
        else
        {
            quickSort_optim(nums, pivot + 1, right);
            left = pivot - 1;
        }
    }
}

int main()
{

    return 0;
}