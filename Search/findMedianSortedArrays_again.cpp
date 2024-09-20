#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

// 排除法 + 二分搜索
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int s1 = nums1.size(), s2 = nums2.size();
        double l = findKthNum(nums1, 0, s1 - 1, nums2, 0, s2 - 1, (s1 + s2 + 1) / 2);
        double r = findKthNum(nums1, 0, s1 - 1, nums2, 0, s2 - 1, (s1 + s2 + 2) / 2);
        return (l + r) / 2;
    }

    // 参数列表加上const，表明函数不会修改输入数组，使编译器能进行更多优化，避免不必要的复制或更好处理缓存
    double findKthNum(const vector<int> &nums1, int left1, int right1, const vector<int> &nums2, int left2, int right2, int k)
    {
        int len1 = right1 - left1 + 1; // nums1剩余元素
        int len2 = right2 - left2 + 1;
        if (len1 > len2) // 保证nums1长度不大于nums2长度
        {
            return findKthNum(nums2, left2, right2, nums1, left1, right1, k);
        }
        if (len1 == 0) // 因为要找的是中位数，总有一个数组要先耗完
        {
            return nums2[left2 + k - 1];
        }
        if (k == 1) // 递归到头了, 逻辑上，k=1就不能在进行划分比较了，算术上，1/2=0
            return min(nums1[left1], nums2[left2]);

        int i = left1 + min(len1, k / 2) - 1;
        int j = left2 + min(len2, k / 2) - 1;
        int val1 = nums1[i];
        int val2 = nums2[j];
        if (val1 > val2)
        {
            return findKthNum(nums1, left1, right1, nums2, j + 1, right2, k - (j - left2 + 1));
        }
        else
        {
            return findKthNum(nums1, i + 1, right1, nums2, left2, right2, k - (i - left1 + 1));
        }
    };
};

int main()
{
    return 0;
}