#include <string>
#include <iostream>
#include <stack>
#include <vector>
#include <stdio.h>

using namespace std;

// 字符串解码
class Solution
{
public:
    // 栈的核心在于后进先出-对应了括号运算法则
    string decodeString(string s)
    {
        stack<pair<int, string>> st;
        string res = ""; // 存储块内字符
        int num = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                num *= 10;
                num += s[i] - '0';
            }
            else if (s[i] == '[') // 入栈-《记录之前的信息，等待还原》
            {
                st.push(make_pair(num, res));
                num = 0;
                res = "";
            }
            else if (s[i] == ']') // 出栈
            {
                int cnt = st.top().first;
                string a = st.top().second; // a是上一个[]中的部分字符串，待拼接的
                st.pop();
                for (int i = 0; i < cnt; i++)
                {
                    a += res;
                }
                res = a;
            }
            else if (s[i] >= 'a' && s[i] <= 'z')
            {
                res += s[i];
            }
        }
        return res;
    }
};