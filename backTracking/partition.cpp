#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

// 分割回文串
// 每个子串都是回文串、单字母也是回文串
// 思路：在当前选择子串i..j是回文串情况下，从j+1开始向后遍历
// 当符合条件，也就是j能溢出到s.size()时，才是满足条件的答案
class Solution
{
private:
    vector<vector<int>> f;      // 动态规划-状态转移表
    vector<vector<string>> ret; // 答案
    vector<string> ans;         // 暂存字符串
    int n;                      // 字符串长度

public:
    // 回溯大方向：遍历整个字符串
    void dfs(const string &s, int i)
    {
        if (i == n) // i==n是已经遍历完成了，只有最后一个元素也被包含，i越界才能视为有效ans被push进ret
        {
            ret.push_back(ans);
            return;
        }
        for (int j = i; j < n; ++j)
        {
            if (f[i][j])
            {
                ans.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);  // 回溯思路：一旦选了这块，就从下一个索引开始看哪些是回文串
                ans.pop_back(); // 回退过后就可以移动j，扩大子串大小了
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        n = s.size();
        f.assign(n, vector<int>(n, true)); // 初始化DP边界条件：整体数值都设为true
        // DP预处理，字符串i..j是否回文字符串
        // i相当于左指针，j相当于右指针
        // 从右向左，从中间到两端不断延展
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                // 不断从左下角取值进行转移，当前值不同就不是回文串
                f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1]; // 当j=i+1，两者位置刚好交换，也应该要满足的
            }
        }

        dfs(s, 0);
        return ret;
    }
};

int main()
{

    return 0;
}