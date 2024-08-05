#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

vector<bool> v = {0, 0, 0, 0, 0, 0, 1, 1, 1};

// The API isBadVersion is defined for you.
bool isBadVersion(int version)
{
    return v[version - 1];
}

class Solution
{
    // 思路：二分搜索
public:
    int firstBadVersion(int n)
    {
        int i = 1, j = n;
        while (i <= j)
        {
            int m = i + (j - i) / 2; // 寻找中点
            if (isBadVersion(m))
            {
                j = m - 1;
            }
            else
            {
                i = m + 1;
            }
        }
        return i; // i最终会移到bad的位置，就是第一个损坏的版本
    }
};

// 耗时更低的版本
class Solution2
{
public:
    int firstBadVersion(int n)
    {
        int left = 1, right = n;
        while (left < right) // 少判断一次
        {
            int mid = ((right - left) >> 1) + left; // 以为操作比除数时间复杂度更低
            if (isBadVersion(mid))
            {
                right = mid; // right就锁在bad的位置，等待left进行收敛
            }
            else
            {
                left = mid + 1;
            }
        }
        return right;
    }
};

int main()
{
    Solution *s = new Solution();
    int ret = s->firstBadVersion(9);
    return 0;
}