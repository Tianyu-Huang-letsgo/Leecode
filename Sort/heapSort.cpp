#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
// 堆排序

// 堆的特性：当前节点的值大于/小于所有子节点的值
// 将节点i下移到正确的位置(出堆-从上到下)
void siftDown(vector<int> &nums, int i, int n)
{
    while (true)
    {
        int l = 2 * i + 1, r = 2 * i + 2;
        int root = i;
        // 说白了就是跟左右子树比在进行交换
        if (l < n && nums[l] > nums[root])
        {
            root = l;
        }
        if (r < n && nums[r] > nums[root])
        {
            root = r;
        }
        if (root = i)
        {
            break;
        }
        swap(nums[root], nums[i]);
        i = root;
    }
}

void heapSort(vector<int> &nums)
{
    int n = nums.size();
    // 1.建大顶堆(堆的数组表示是一棵完全二叉树)
    for (int i = (n - 1) / 2; i >= 0; --i)
    {
        siftDown(nums, i, n);
    }

    // 2. 从最大堆中提取元素
    for (int i = n - 1; i > 0; --i)
    {
        swap(nums[0], nums[i]); // 只用循环n-1次，因为如果只剩一个元素，交换也没有意义了
        siftDown(nums, 0, i);
    }
}

int main()
{
    return 0;
}
