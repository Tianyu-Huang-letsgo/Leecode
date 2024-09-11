#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// 最长有效括号
// 格式正确且连续
// 子串内的所有子串左括号都大于等于右括号个数

// 方法一：DP状态转移
// 含义 dp[i]:以下标 i 字符结尾的最长有效括号的长度
// 如果s[i] == '(', dp[i] == 0;
// 如果s[i] == ')'
// 1. 如果s[i-1] == '(', dp[i] = dp[i-2] + 2;    凑满一个
// 2. 如果s[i-1] == ')', dp[i-1] + dp[i - dp[i-1] -2] + 2;
class Solution2
{
public:
    int longestValidParentheses(string s)
    {
        if (s.length() == 1)
        {
            return 0;
        }
        int n = s.length();
        int maxans = 0;
        vector<int> dp(n + 1, 0);
        for (int i = 2; i <= n; ++i)
        {
            if (s[i - 1] == ')')
            {
                if (s[i - 2] == '(')
                {
                    dp[i] = dp[i - 2] + 2;
                }
                else
                {
                    // 前面得够位置留有匹配，当前')'才有机会跟'('匹配上
                    if (i - dp[i - 1] - 2 >= 0 && s[i - dp[i - 1] - 2] == '(')
                    {
                        dp[i] = dp[i - 1] + (i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                    }
                }
            }
            maxans = max(maxans, dp[i]);
        }
        return maxans;
    }
};

// 方法2：原理性遍历
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int left = 0, right = 0;
        int maxcnt = 0, cnt = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '(')
            {
                ++left;
            }
            else
            {
                ++right;
            }
            if (left == right)
            {
                cnt += (left + right);
                maxcnt = max(maxcnt, cnt);
                cnt = 0;
            }
            if (right > left)
            {
                left = 0;
                right = 0;
                cnt = 0;
            }
        }
        left = 0, right = 0, cnt = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == '(')
            {
                ++left;
            }
            else
            {
                ++right;
            }
            if (left == right)
            {
                cnt += (left + right);
                maxcnt = max(maxcnt, cnt);
                cnt = 0;
            }
            if (right < left)
            {
                left = 0;
                right = 0;
                cnt = 0;
            }
        }
        return maxcnt;
    }
};

int main()
{
    Solution *s = new Solution();
    string str = "()(())";
    int ret = s->longestValidParentheses(str);
    return 0;
}