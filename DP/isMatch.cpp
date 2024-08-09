#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    // 将字符串匹配转化为最后一个字符的对比与除第一个字符外的其他子字符串的对比
    bool isMatch(string s, string p)
    {
        int lens = s.size();                                              // i
        int lenp = p.size();                                              // j
        vector<vector<bool>> dp(lens + 1, vector<bool>(lenp + 1, false)); // 因为包含了空字串的情况
        // 初始化
        dp[0][0] = true;                   // 两个空字串
        for (int j = 1; j < lenp + 1; j++) // 找出s为空 但p因为* 为空的情况（更新dp表第一行）
        {
            if (p[j] == '*') // p的第j+1个字符为'*'
            {
                dp[0][j + 1] = dp[0][j - 1]; // '*'将第j个字符干掉
            }
        }
        // 更新
        for (int i = 1; i < lens + 1; i++)
        {
            for (int j = 1; j < lenp + 1; j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.') // 情况1：符合，直接更新
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*') // 情况2：考虑*的情况 p的第j个字符是'*'
                {
                    if (s[i - 1] == p[j - 2] || p[j - 2] == '.')
                    {
                        dp[i][j] = dp[i][j - 2] || dp[i - 1][j - 2] || dp[i - 1][j]; // 分别是  重复0次；重复1次；重复2次及以上！！！这里是核心，就是这一种状态可能会由这三种情况转换而来，只要其中一种是匹配的，就认为从这一种转换过来，三种都不匹配，那就是不匹配了。
                    }
                    else // s[i-1] p[j-2]不匹配  *需要重复0次,就是把p[j-2]干掉
                    {
                        dp[i][j] = dp[i][j - 2];
                    }
                }
            }
        }
        return dp[lens][lenp];
    }
};

int main()
{
    Solution *s = new Solution();
    return 0;
}
