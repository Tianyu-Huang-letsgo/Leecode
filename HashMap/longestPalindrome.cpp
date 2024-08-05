#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    // 思路：中间数只用单数，其他凑够双数就行
    int longestPalindrome(string s)
    {
        int hash[128] = {0};
        for (int i = 0; i < s.length();i++)
        {
            hash[s[i]]++;
        }
        if(s.length() == 1)
            return 1;
        int ret = 0;
        int flag = false;
        for (int i = 0; i < s.length();i++)
        {
            int num = hash[s[i]] / 2;
            if (hash[s[i]] % 2 != 0){
                flag = true;
            }
            hash[s[i]] = 0;
            ret += num*2;
        }
        if(flag){
            return ret + 1;
        }
        else{
            return ret;
        }
    }
};

int main()
{
    Solution *s = new Solution();
    int length = s->longestPalindrome("aaabbbcc");
    cout << length;
    return 0;
}