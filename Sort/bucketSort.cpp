#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

// 桶排序：适用于数据量大且分布平均的样本
// 缺点：非原地排序，占用较大的额外内存
void bucketSort(vector<float> &nums)
{
    int n = nums.size();
    int k = n / 2; // 初始化n/2个桶
    vector<vector<float>> buckets(k);

    // 确定数组中的最大值和最小值
    float minVal = *min_element(nums.begin(), nums.end());
    float maxVal = *max_element(nums.begin(), nums.end());
    float range = maxVal - minVal;

    // 1. 将元素放进桶中
    for (float num : nums)
    {
        // 计算一个值的百分比，再*k，得到桶的索引
        int ind = (int)((num - minVal) / range * k); // 根据范围调整索引计算
        if (ind == k)                                // 有可能最大值就是范围这种情况
            ind = k - 1;                             // 处理边界情况
        buckets[ind].push_back(num);
    }

    // 2. 分别对各桶进行排序
    for (auto &b : buckets)
    { // 使用引用
        sort(b.begin(), b.end());
    }

    // 3. 合并桶中元素到原数组中
    int index = 0;
    for (const auto &bucket : buckets)
    {
        for (float num : bucket)
        {
            nums[index++] = num;
        }
    }
}

int main()
{
    return 0;
}