#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// 72. 编辑距离
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= m; ++i)
        {
            dp[0][i] = i;
        }

        for (int i = 1; i <= n; ++i)
        {
            dp[i][0] = i;
            for (int j = 1; j <= m; ++j)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1]; // 如果当前字符相同，仅考虑此前字符串编辑路径
                }
                else
                {
                    dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]);     // 插入（一定是插入相同的字符）、删除
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]) + 1; // 替换
                }
            }
        }
        return dp[n][m];
    }
};

int main()
{
    return 0;
}