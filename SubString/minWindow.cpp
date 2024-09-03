#include <iostream>
#include <stdio.h>
#include <string>
#include <unordered_map>

using namespace std;

// 思路：双指针 + 哈希表
// 窗口不断扩大（向右）缩小（向左），直至完成遍历
class Solution
{
public:
    string minWindow(string s, string t)
    {
        // hash1:t中字符统计； hash2:滑动窗口字符统计
        int hash1[128] = {0}, hash2[128] = {0}, n = 0;
        for (auto ch : t)
            if (hash1[ch]++ == 0)
                ++n; // 直接计算类别数

        int star = -1, minlen = INT_MAX;
        for (int left = 0, right = 0, count = 0; right < s.size(); ++right)
        {
            char in = s[right]; // 即将进入的元素
            if (++hash2[in] == hash1[in])
                ++count;
            while (count == n) // 一旦类别数凑齐
            {
                if (right - left + 1 < minlen) // 若长度更小
                {
                    star = left; // 一旦这个值被刷新，才是有答案的
                    minlen = right - left + 1;
                }
                char out = s[left++];           // 即将弹出的元素,满足条件左边界就要向右靠，不断搜索最小窗口
                if (hash2[out]-- == hash1[out]) // 一旦hash2类别数等于再减，计数-1
                    --count;
            }
        }
        return star == -1 ? "" : s.substr(star, minlen);
    }
};

int main()
{
    return 0;
}