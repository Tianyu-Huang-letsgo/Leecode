#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// 划分字母区间
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        // 记录字母最后一次出现下标位置
        int ind[26];
        int s_len = s.length();
        for (int i = 0; i < s_len; i++)
        {
            ind[s[i] - 'a'] = i;
        }

        vector<int> ret;
        int start = 0, end = 0;
        for (int i = 0; i < s_len; i++)
        {
            end = max(end, ind[s[i] - 'a']); // 不断刷新队列中已有元素的最大下标值
            if (i == end)                    // 贪心思想体现在：寻找每个片段可能的最小结束下标
            {
                ret.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return ret;
    }
};

int main()
{
    return 0;
}