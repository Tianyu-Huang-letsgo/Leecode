#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
// 归并排序(稳定)
// 左子树区间：[left, mid]; 右子树区间：[mid+1, right]
void merge(vector<int> &nums, int left, int mid, int right)
{
    vector<int> tmp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right)
    {
        if (nums[i] <= nums[j])
        {
            tmp[k++] = nums[i++];
        }
        else
        {
            tmp[k++] = nums[j++];
        }
    }
    while (i <= mid)
    {
        tmp[k++] = nums[i++];
    }
    while (j <= right)
    {
        tmp[k++] = nums[j++];
    }
    for (int cnt = 0; cnt < tmp.size(); ++cnt)
    {
        nums[left + cnt] = tmp[cnt];
    }
}

void mergeSort(vector<int> &nums, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = (left + right) >> 1;
    mergeSort(nums, left, mid);      // 左递归
    mergeSort(nums, mid + 1, right); // 右递归
    merge(nums, left, mid, right);   // 合并（结果处理，将合并好的结果返回上一层）
}

int main()
{
    return 0;
}