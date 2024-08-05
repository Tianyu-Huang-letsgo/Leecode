#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        // 思路：
        // 1. 创建原始指针，指向/遍历子序列
        // 2. 原序列存在该字符串，原始指针加一，如果原始指针能遍历满子序列，返回true
        // 双指针：分别指向双序列
        int ptr_raw = 0;
        for (int j = 0; j < t.length(); j++)
        {
            if (ptr_raw >= s.length())
            {
                break;
            }
            if (t[j] == s[ptr_raw])
            {
                ptr_raw++;
            }
        }
        if (ptr_raw == s.length())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Solution *s = new Solution();
    bool ret = s->isSubsequence("abc", "ahsdfbsof");
    cout << ret;
    return 0;
}