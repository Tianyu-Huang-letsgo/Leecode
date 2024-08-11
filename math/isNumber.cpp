#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isNumber(string s)
    {
        // 定义状态转移表states，**每一个状态可以根据输入值转移到另一种状态(int)**
        // 状态转移表约束了当前某个状态state只能有这些确定的输入，如果输入不在表中，则说明数字无效。
        vector<unordered_map<char, int>> states = {
            {{' ', 0}, {'s', 1}, {'.', 4}, {'d', 2}}, // state0: start with blank
            {{'d', 2}, {'.', 4}},                     // state1: e前的符号
            {{'d', 2}, {'e', 5}, {' ', 8}, {'.', 3}}, // state2: dot前的数字
            {{'e', 5}, {'d', 3}, {' ', 8}},           // state3: dot后的数字
            {{'d', 3}},                               // state4 :dot前为空时，dot后的数字(结尾为.也是正确的格式)
            {{'d', 7}, {'s', 6}},                     // state5: e
            {{'d', 7}},                               // state6: e之后的符号
            {{'d', 7}, {' ', 8}},                     // state7: e之后的数字
            {{' ', 8}}                                // state8: blank
        };

        int p = 0;       // 状态从0开始
        for (char c : s) // 遍历字符串，每一个字符都是状态机的一个输入
        {
            char t; // type
            if (c >= '0' && c <= '9')
            {
                t = 'd';
            }
            else if (c == '+' || c == '-')
            {
                t = 's';
            }
            else if (c == 'e' || c == 'E')
            {
                t = 'e';
            }
            else if (c == ' ' || c == '.') // 字符等于空格或.时候，使用本身，不改变
            {
                t = c;
            }
            else
            {
                t = '?';
            }

            if (states[p].count(t) == 0) // 在状态表中没有搜索到该输入，错误格式。
                return false;

            p = states[p][t];
        }
        return p == 2 || p == 3 || p == 7 || p == 8;
    }
};

int main()
{

    return 0;
}