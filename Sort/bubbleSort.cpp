#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

// 冒泡排序（稳定）
void bubbleSort(vector<int> &nums)
{
    int n = nums.size();

    for (int i = n - 1; i > 0; --i)
    {
        bool flag = true; // 标志位应该放在外循环中，因为每次冒泡都要看是否进行了交换才又作用
        for (int j = 0; j < i; ++j)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]); // 注意点：这个j+i最后是等于i，与i进行比较的
                flag = false;
            }
        }
        if (flag == true)
        {
            break;
        }
    }
}

int main()
{
    return 0;
}