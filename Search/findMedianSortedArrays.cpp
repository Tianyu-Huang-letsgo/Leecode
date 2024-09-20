#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// 寻找两个正序数组的中位数
// 合并两数组，进行搜索，不符合要求
class Solution1
{
public:
#include <vector>

    double findMedianSortedArrays1(const std::vector<int> &nums1, const std::vector<int> &nums2)
    {
        std::vector<int> nums;
        int m = nums1.size();
        int n = nums2.size();
        nums.resize(m + n);

        if (m == 0)
        {
            if (n % 2 == 0)
            {
                return (nums2[n / 2 - 1] + nums2[n / 2]) / 2.0;
            }
            else
            {
                return nums2[n / 2];
            }
        }
        if (n == 0)
        {
            if (m % 2 == 0)
            {
                return (nums1[m / 2 - 1] + nums1[m / 2]) / 2.0;
            }
            else
            {
                return nums1[m / 2];
            }
        }

        int count = 0;
        int i = 0, j = 0;
        while (count != (m + n))
        {
            // 其中一块遍历完了，将另一块所有元素补充道nums上
            if (i == m)
            {
                while (j != n)
                {
                    nums[count++] = nums2[j++];
                }
                break;
            }
            if (j == n)
            {
                while (i != m)
                {
                    nums[count++] = nums1[i++];
                }
                break;
            }

            if (nums1[i] < nums2[j])
            {
                nums[count++] = nums1[i++];
            }
            else
            {
                nums[count++] = nums2[j++];
            }
        }

        if (count % 2 == 0)
        {
            return (nums[count / 2 - 1] + nums[count / 2]) / 2.0; // 类型提升
        }
        else
        {
            return nums[count / 2];
        }
    }
};

// 排除+二分法搜索，符合要求
class Solution2
{
public:
    double findMedianSortedArrays(const std::vector<int> &nums1, const std::vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        int left = (n + m + 1) / 2;
        int right = (n + m + 2) / 2;
        // Combine the cases for even and odd total length
        return (getKth(nums1, 0, n - 1, nums2, 0, m - 1, left) +
                getKth(nums1, 0, n - 1, nums2, 0, m - 1, right)) *
               0.5;
    }

private:
    int getKth(const std::vector<int> &nums1, int start1, int end1, const std::vector<int> &nums2, int start2, int end2, int k)
    {
        // 数组长度
        int len1 = end1 - start1 + 1;
        int len2 = end2 - start2 + 1;
        // 感觉这样是为了剪枝，一个数组遍历完，直接可搜索另外的数组
        // 保证数组1长度不大于数组2
        if (len1 > len2)
            return getKth(nums2, start2, end2, nums1, start1, end1, k);
        if (len1 == 0) // 数组1最先没
            return nums2[start2 + k - 1];

        if (k == 1) // 递归到头了
            return std::min(nums1[start1], nums2[start2]);

        int i = start1 + std::min(len1, k / 2) - 1; // 指向数组1的指针， -1是为了将自身也要算上，min()得到的是计数元素个数
        int j = start2 + std::min(len2, k / 2) - 1; // 指向数组2的指针

        if (nums1[i] > nums2[j])
        {
            return getKth(nums1, start1, end1, nums2, j + 1, end2, k - (j - start2 + 1)); // +1是为了把start那个数也算上去，最后一个参数表示的是个数（第k小的数）
        }
        else
        {
            return getKth(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1)); // 两数相等，优先干掉数组1的元素
        }
    }
};

int main()
{
    return 0;
}