#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        // 思路：使用双指针从尾部分别从开始遍历，通过字符ASCII码进行计算出字符，叠加
        string ret_str;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        bool flag = false; // 进位标志
        while (i >= 0 && j >= 0)
        {
            char ch = num1[i] + num2[j] - '0';
            char ret_ch;
            if (ch > '9')
            {
                ret_ch = '0' + ch - '9' - 1 + flag;
                flag = true;
            }
            else
            {
                ret_ch = ch + flag;
                if (ret_ch > '9')
                {
                    flag = true;
                    ret_ch = '0';
                }
                else
                {
                    flag = false;
                }
            }
            ret_str = ret_ch + ret_str;
            i--;
            j--;
        }
        while (i >= 0)
        {
            char ret_ch;
            ret_ch = num1[i] + flag;
            ret_str = ret_ch + ret_str;
            i--;
        }
        while (j >= 0)
        {
            char ret_ch;
            ret_ch = num2[j] + flag;
            ret_str = ret_ch + ret_str;
        }
        if (flag)
        {
            ret_str = '1' + ret_str;
        }
        return ret_str;
    }
};

int main()
{

    Solution *s = new Solution();
    string ret = s->addStrings("000", "000");
    return 0;
}