#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution
{
public:
    // 思路：大方向是使用前后双指针不断包裹最大不重复子串，使用哈希表记录出现过的字符，碰到出现过的字符则i坐标不断移动直至哈希表调整为1
    // 卡点：在整体无重复字符串的时候出现了失误，无重复字符则子字符串长度应该不断递增；
    // 应设置一个最大长度作为记录，一个变动字符串随着i的滑动不断更新长度。
    int lengthOfLongestSubstring(string s)
    {
        int length = 0;
        int max_length = 0;
        int i = 0;
        int j = 0;
        int hash[128] = {0};
        bool flag = true;
        while (j != s.length())
        {
            hash[s[j]]++;
            if (hash[s[j]] == 1)
            {
                length++;
            }
            while (hash[s[j]] >= 2)
            {
                max_length = max_length > length ? max_length : length;
                length = j - i; // length会在下一次没有重复字符的时候刷新长度1
                hash[s[i]]--;
                i++;
            }
            j++;
        }
        return max_length = max_length > length ? max_length : length;
    }
};

int main()
{
    Solution *s = new Solution();
    int len = s->lengthOfLongestSubstring("aab");
    cout << len;

    return 0;
}