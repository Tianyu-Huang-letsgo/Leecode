#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

// 无重复字符的最长子串
// 双指针/滑动窗口
class Solution
{
public:
    // 思路：大方向是使用前后双指针不断包裹最大不重复子串，使用哈希表记录出现过的字符，碰到出现过的字符则i坐标不断移动直至哈希表调整为1
    // 卡点：在整体无重复字符串的时候出现了失误，无重复字符则子字符串长度应该不断递增；
    // 应设置一个最大长度作为记录，一个变动长度随着i的滑动不断更新长度。
    int lengthOfLongestSubstring(string s)
    {
        int hash[128] = {0};
        int len = 0;
        int max_len = 0;
        int i = 0, j = 0;
        while (j != s.length())
        {
            hash[s[j]]++;
            if (hash[s[j]] == 1) // 未遍历过该元素
            {
                len++;
            }
            else // 已经遍历过该元素
            {
                max_len = max(max_len, len - 1);
                while (hash[s[j]] > 1)
                {
                    hash[s[i]]--;
                    i++;
                }
                len = j - i + 1;
            }
            j++; // 这里要注意：第j个元素在循环开始已经遍历过了，下一次循环一定要进行偏移。
            max_len = max(max_len, len);
        }
        return max_len;
    }
};

int main()
{
    Solution *s = new Solution();
    int len = s->lengthOfLongestSubstring("abcabcbb");
    cout << len;

    return 0;
}