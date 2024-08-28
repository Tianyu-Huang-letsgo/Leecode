#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// 有效的括号
class Solution
{
public:
    bool isValid(string s)
    {
        if (s.size() % 2 != 0)
            return false;
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            // 栈这个数据结构保证了顺序性：后进先出
            // 指左打右，有利于后续判断
            if (s[i] == '(')
                st.push(')');
            else if (s[i] == '[')
                st.push(']');
            else if (s[i] == '{')
                st.push('}');
            // 这里排除两种情况，左右不匹配
            else if (st.empty() || s[i] != st.top())
                return false;
            else
                st.pop();
        }
        return st.empty(); // 防止右边还有的情况
    }
};

int main()
{
    return 0;
}