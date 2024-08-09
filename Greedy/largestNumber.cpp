#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // 根据nums元素中的首元素进行排序、拼接
    string largestNumber(vector<int> &nums)
    {
        string str = "";
        vector<string> str_nums(nums.size(), "");
        for (int i = 0; i < nums.size(); i++)
        {
            str_nums[i] = to_string(nums[i]);
        }

        sort(str_nums.begin(), str_nums.end(), [=](const string &a, const string &b)
             { return a + b > b + a; }); // 字符串的字典序比较是可以直接通过>和<操作符实现的

        for (auto num : str_nums)
        {
            str += num;
        }
        if (str[0] == '0')
        {
            str = "0";
        }
        return str;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> v = {999999998, 999999997, 999999999};
    string ret = s->largestNumber(v);
    return 0;
}