#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        // 初始思路：倒序遍历字符串，将非空字符压栈，遇空格再出栈保持单词顺序一致；
        // 只有当会再次压栈才会在ret字符串中加入' ',消除前后字符影响
        stack<char> st;
        string ret;
        int flag = false;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
            {
                continue;
            }
            st.push(s[i]);
            if (flag)
            {
                ret += ' ';
                flag = false;
            }
            if (i >= 1 && s[i - 1] == ' ' || i == 0)
            {
                while (!st.empty())
                {
                    ret += st.top();
                    st.pop();
                }
                flag = true;
            }
        }
        return ret;
    }
};

int main()
{
    Solution *s = new Solution();
    string ret = s->reverseWords("   the sky is blue   ");
    cout << ret;
    return 0;
}