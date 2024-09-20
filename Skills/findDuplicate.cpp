#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

// 287. 寻找重复数
// 关键：有n+1个数字，范围都在[1,n]内
class Solution
{
public:
    // 难点：根据题目要求，不能使用哈希表记录数字出现个数
    // 官方解题思路：使用数字计数判断，cnt[i]表示<=i出现的个数，因为有n+1个数，故只要数字重复了，cnt[i]>i,cnt[i-1]<=i
    int findDuplicate(vector<int> &nums)
    {
        int l = 1, r = nums.size() - 1;
        int res;
        while (l <= r)
        {
            int mid = (l + r) >> 1; // mid作为哨兵旨在寻找重复数，一旦cnt>mid，即mid必为重复数
            int cnt = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                cnt += nums[i] <= mid; // 使用二分查找
            }
            if (cnt <= mid) // 计数小于中位数-重复数在右侧
            {
                l = mid + 1;
            }
            else // 计数大于中位数-重复数在左侧
            {
                res = mid; // res取自向左靠前的数，不断逼近答案
                r = mid - 1;
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}