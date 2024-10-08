#include <stdio.h>
#include <vector>

using namespace std;

// 寻找重复数
class Solution
{
public:
    // 难点：根据题目要求，不能使用哈希表记录数字出现个数
    // 前置条件：数字都在[1, n]范围内，数组有n+1个数
    // 官方解题思路：使用**数字计数**判断，cnt[i]表示<=i出现的个数，因为有n+1个数，故只要数字重复了，cnt[i]>i,cnt[i-1]<=i
    int findDuplicate(vector<int> &nums)
    {
        int l = 1, r = nums.size() - 1;
        int res;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            int cnt = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                cnt += nums[i] <= mid; // 跟nums的排序就没有关系的
            }
            if (cnt <= mid)
            {
                l = mid + 1;
            }
            else
            {
                res = mid;
                r = mid - 1;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> v = {1, 1};
    Solution *s = new Solution();
    int ret = s->findDuplicate(v);
    return 0;
}