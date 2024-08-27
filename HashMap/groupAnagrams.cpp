#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 字母异位词分组
class Solution
{
public:
    // 思路：字母异位词排序后是一样的，以此排序后字符作为hash的key，各字母异位词作为键中对应值
    // 使用vector<string>作为值可实现一键多值
    // 核心是需要找到《相同点》
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> hash;
        vector<vector<string>> ans;
        for (string s : strs)
        {
            string s_tmp = s;
            sort(s.begin(), s.end());
            hash[s].emplace_back(s_tmp);
        }
        for (auto iter = hash.begin(); iter != hash.end(); iter++)
        {
            ans.emplace_back(iter->second); // 性能：emplace_back() 通常提供更好的性能，因为它直接在容器的内存中构造对象，减少了一次或多次复制或移动构造的需要。
        }
        return ans;
    }
};

int main()
{

    return 0;
}