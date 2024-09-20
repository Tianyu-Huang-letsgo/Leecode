#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

// 1143. 最长公共子序列
// 子序列：不一定连续
// 子串/子数组：一般情况下是连续的
// 本质上就是和01背包一样，都是选和不选的问题
// dp[i][j]:text1前i个字符与text2前j个字符组成的最长公共序列
// 状态转移：
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                // 末尾字符相同，同时去掉
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else // 末尾字符不同，取去掉一个的最大值
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};

int main()
{
    string str = "abc";
    string t = "def";
    Solution *s = new Solution();
    int ret = s->longestCommonSubsequence(str, t);
    return 0;
}