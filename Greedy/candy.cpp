#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
    // 难点： 两个相邻孩子评分更高的孩子会获得更多糖果
    // 贪心策略：A B
    // 左规则： rating(B) > rating(A) B的数量为A++
    // 右规则： rating(A) > rating(B) A的数量为B++
    // 返回两次遍历的最大值，也就是同一个小朋友的糖果数既满足左规则又满足右规则;核心：取最大值会同时满足左规则和右规则
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        if (n == 1)
        {
            return 1;
        }
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        for (int i = 1; i < n; ++i)
        {
            if (ratings[i] > ratings[i - 1])
            {
                left[i] = left[i - 1] + 1;
            }
        }
        int ret = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
            {
                ret += max(left[i], right[i]);
                continue;
            }
            if (ratings[i] > ratings[i + 1])
            {
                right[i] = right[i + 1] + 1;
            }
            ret += max(left[i], right[i]);
        }
        return ret;
    }
};

int main()
{

    return 0;
}