#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // 思路：以2，3，5作为基底进行相乘
    int nthUglyNumber(int n)
    {
        int a = 0, b = 0, c = 0;
        int res[n];
        res[0] = 1;
        for (int i = 1; i < n; i++)
        {
            // 使用三指针分别对应应该乘2，乘3，乘5的数字
            // 避免重复res[i]的操作：
            // 1. 将当前相乘后的最小值存入res，确保顺序；2. 如果res[i]已经等于乘以后的数字了，表示这个值已经不需要再多乘一次了，指针++.
            // 直观上是每一个相同的丑数都应该乘以2，3，5，但是避免出现重复数字的情况，采用了三指针。
            int n2 = res[a] * 2, n3 = res[b] * 3, n5 = res[c] * 5;
            res[i] = min(min(n2, n3), n5);
            if (n2 == res[i])
                a++;
            if (n3 == res[i])
                b++;
            if (n5 == res[i])
                c++;
        }
        return res[n - 1];
    }
};

int main()
{
    Solution *s = new Solution();
    return 0;
}
