#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// 括号生成
// 对于括号的有效性，'('必须在前，而且所有子串中，'('数量都会大于')'数量
// 难点：可能会造成很多次重复
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        char P[2] = {'(', ')'};
        vector<string> ret;
        string s = "";
        dfs(n, s, ret, 0, 0);
        return ret;
    }

private:
    // n：对数，subStr：当前子串，ret：结果保存，l_cnt：当前子串左括号个数，r_cnt:当前子串右括号个数
    void dfs(const int n, string &subStr, vector<string> &ret, int l_cnt, int r_cnt)
    {
        if (subStr.size() == 2 * n)
        {
            ret.push_back(subStr);
            return;
        }

        // 回溯的核心：当前层的选择问题。
        // 1. 为什么优先选左括号：作为合理性，每一个右括号对应一个左括号，要先有左括号才能有右括号；
        // 2. 左括号回退之后，右括号满足条件也可以选择右括号
        if (l_cnt < n)
        {
            subStr.push_back('(');
            dfs(n, subStr, ret, l_cnt + 1, r_cnt);
            subStr.pop_back();
        }
        if (r_cnt < l_cnt)
        {
            subStr.push_back(')');
            dfs(n, subStr, ret, l_cnt, r_cnt + 1);
            subStr.pop_back();
        }
    }
};

int main()
{

    return 0;
}