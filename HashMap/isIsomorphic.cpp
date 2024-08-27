#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

// 同构字符串
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        // 思路：创建一个hash_map,如果还没映射好，建立映射；对其中一个字符串进行遍历，另一个字符串对应不在映射上，则false;
        // 题意理解：单向映射（无语）
        // 每一个字符有两个属性，映射到某个字符上，被某个字符映射了
        int hash_map[128] = {0};
        bool hash_beMap[128] = {0};
        if (s.length() != t.length())
            return false;
        for (int i = 0; i < s.length(); i++)
        {
            if (hash_map[s[i]] == 0)
            { // 当前字符未映射过
                // t[i]没被映射过，才能进行映射
                if (hash_beMap[t[i]] == 0)
                {
                    hash_map[s[i]] = t[i];
                    hash_beMap[t[i]] = 1;
                }
                else
                {
                    return false;
                }
            }
            else
            { // 当前字符映射过，但映射值与当前匹配值不一致
                if (hash_map[s[i]] != t[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution *s = new Solution();
    bool isIs = s->isIsomorphic("badc", "baba");
    cout << isIs;
}