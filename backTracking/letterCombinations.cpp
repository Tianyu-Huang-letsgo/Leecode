#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// 电话号码的字母组合
// 类似于子集合问题，这里是每个元素必须抽一个子元素，且仅能抽一个元素，不能不抽，标准遍历问题
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits == "")
        {
            return vector<string>();
        }
        int len = digits.length();
        string tmp_s;
        dfs(len, tmp_s, 0, digits);
        return this->ret_;
    }

private:
    vector<string> ret_;
    vector<string> map_ = {{}, {}, "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    // 数字个数、当前字符串、当前数字、当前下标、输入数字组
    void dfs(const int &len, string &tmp_s, int cur_num, string &digits)
    {
        if (tmp_s.length() == len)
        {
            this->ret_.push_back(tmp_s);
            return;
        }
        for (int i = 0; i < map_[digits[cur_num] - '0'].size(); i++)
        {
            tmp_s.push_back(map_[digits[cur_num] - '0'][i]);

            dfs(len, tmp_s, cur_num + 1, digits);
            tmp_s.pop_back();
        }
    }
};

int main()
{
    string str = "23";
    Solution *s = new Solution();
    vector<string> ret = s->letterCombinations(str);
    return 0;
}