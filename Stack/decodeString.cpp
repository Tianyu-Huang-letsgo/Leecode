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
        // 创建栈用于压数量num和字符串res
        stack<pair<int, string>> sta;
        int num = 0;
        string res = ""; // res表示当前[]内字符串序列
        for (int i = 0; i < s.size(); i++)
        {
            // 临时存入上一个数字num
            if (s[i] <= '9' && s[i] >= '0')
            {
                num *= 10; // 这里*10是为了应对多位数的情况：56，这里num起始值是0
                num += (s[i] - '0');
            }
            else if (s[i] == '[')
            {                                  // '['对应入栈，存放临时数据
                sta.push(make_pair(num, res)); // 入栈-《记录之前的信息，等待还原》
                num = 0;
                res = ""; // 这里字符串清空，是为了进行'[]'栈内复制使用
            }
            else if (s[i] == ']')
            { // ']'对应出栈，拿出《最近一次》存放的临时数据
                int n = sta.top().first;
                string a = sta.top().second;
                sta.pop();
                // 这里是最关键最难的一步，碰到']'需要进行原始字符串更新
                for (int i = 0; i < n; i++)
                {
                    a = a + res; // 不断往队列后添加res字符串
                }
                res = a;
            }
            else
            { // 遇到字符存入字符
                res += s[i];
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}