#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

// 分割回文串（重做）
class Solution
{
private:
    vector<vector<bool>> f;     // 动态规划-状态转移表
    vector<vector<string>> ret; // 答案
    vector<string> ans;         // 暂存字符串
    int n;                      // 字符串长度

public:
    vector<vector<string>> partition(string s)
    {
        n = s.length();
        // 创建动态规划表的目的，查看f[i][j]:i..j是否回文字符串
        f.assign(n, vector<bool>(n, true)); // 动态规划-状态转移表
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = i + 1; j < n; j++)
            {
                f[i][j] = f[i + 1][j - 1] && s[i] == s[j];
            }
        }
        dfs(s, 0);
        return ret;
    }

    // 状态：字符串， 当前字符索引
    void dfs(string &s, int i)
    {
        if (i == n)
        {
            ret.push_back(ans);
            return;
        }
        for (int j = i; j < n; j++) // 不断向后搜索哪个是回文串
        {
            if (f[i][j])
            {
                ans.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);
                ans.pop_back();
            }
        }
    }
};

int main()
{

    return 0;
}