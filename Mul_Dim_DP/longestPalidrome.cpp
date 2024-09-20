#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

// 5. 最长回文串
// dp[i][j]: 窗口i..j是否回文字符串
class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.length() == 1)
        {
            return s;
        }
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, true));
        int ansmax = 1;
        string ans = "";
        ans += s[0];
        for (int i = n - 1; i >= 0; --i)
        {
            // 回文串状态转移： dp[i + 1][j - 1] == true && s[i] == s[j]
            for (int j = i + 1; j < n; ++j)
            {
                dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
                if (dp[i][j])
                {
                    if (j - i + 1 > ansmax)
                    {
                        ansmax = max(ansmax, j - i + 1);
                        ans = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        return ans;
    }
};

// 更优
class Solution
{
public:
    string longestPalindrome(string s)
    {
        // 以各字符为中心，向外拓展回文子串
        // 时间也是需要n2
        // 需要记录子串的两个边界
        int length = s.length();
        string ans;
        if (!length)
            return ans;
        int max = 0;
        for (int i = 0; i < length; i++)
        {
            char c = s[i];
            int left = i - 1;
            // 步骤一： 数字相同必回文串
            while (left > -1 && s[left] == c)
            {
                left--;
            }
            int right = i + 1;
            while (right < length && s[right] == c)
            {
                right++;
            }
            // 步骤二：除去数字相同部分，字符相同则合并
            while (left > -1 && right < length && s[left] == s[right])
            {
                left--;
                right++;
            }
            int ltmp = right - left - 1; // 这里是因为left，right此时是越界回文的（超了2）， ltmp = right - left + 1 -2;
            if (ltmp > max)
            {
                max = ltmp;
                ans = s.substr(left + 1, ltmp);
            }
        }
        return ans;
    }
};

int main()
{
    Solution *s = new Solution();
    string str = s->longestPalindrome("abba");
    return 0;
}