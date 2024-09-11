#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

// 单词拆分
// 动态规划表含义---dp[i]:前i个字符是否可以被匹配上
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.length(); ++i)
        {
            for (auto word : wordDict)
            {
                if (word.length() <= i)
                {
                    dp[i] = dp[i - word.length()] && (s.substr(i - word.length(), word.length()) == word) || dp[i]; // 转移的本质：加上当前单词之前能匹配上且当前单词也能匹配上，说明可以匹配
                }
            }
        }
        return dp[s.length()];
    }
};

int main()
{
    vector<string> v = {"leet", "code"};
    Solution *s = new Solution();
    bool ret = s->wordBreak("leetcode", v);
    return 0;
}