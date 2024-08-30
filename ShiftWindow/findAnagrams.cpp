#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// 找到字符串中所有的字母异位词
// 字母异位词很重要的特征：字符串对应的哈希表都相同
// 巧妙思路（动态）：字符串中的字母异位词充分条件：1. 字符串长度相同；2. 遍历到字符串相同的时候不能出现哈希表破0
// 变长滑动窗口
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> hash(26, 0); // 26个小写字符
        vector<int> ret;
        int len = p.length();
        // 构建子串哈希表
        for (auto ch : p)
        {
            ++hash[ch - 'a'];
        }
        // r负责开疆拓土
        // 这里的逻辑可以使用反证法证明，相同长度的两段序列，如果其中一个字符不同，必然会在哈希判断时被破坏
        for (int l = 0, r = 0; r < s.length(); r++) // for条件语句仅仅只是堆叠了判断而已，这里思路/写法值得学习
        {
            --hash[s[r] - 'a'];
            while (hash[s[r] - 'a'] < 0) // 核心1：出现哈希不匹配条件，唯一方式是l向右偏移
            {
                ++hash[s[l] - 'a'];
                ++l;
            }
            if (r - l + 1 == len)
            {
                ret.push_back(l);
            }
        }
        return ret;
    }
};

int main()
{
    return 0;
}