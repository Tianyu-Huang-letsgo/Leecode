#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // 神奇点：异或运算有一个重要性质：两个相同数字异或为0，且异或运算满足交换律，所以运算结果与num元素排列无关
    int singleNumber(vector<int> &nums)
    {
        int base = 0;
        for (auto num : nums)
        {
            base ^= num; // 这里的异或本质上也是对所有二进制位进行异或运算，只是抽象出来可以写成 a⊕a
        }
        return base;
    }
};

int main()
{
    vector<int> v = {4, 1, 2, 1, 2};
    Solution *s = new Solution();
    int ret = s->singleNumber(v);
    return 0;
}