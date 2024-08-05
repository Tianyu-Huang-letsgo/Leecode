#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    // 思路：使用二维数组vector<vector<int>>对元素进行记录，再遍历输出
    // numRows有几行表示有几个子vector,而且元素压入时候不用考虑列数
    string convert(string s, int numRows)
    {
        if(numRows == 1){
            return s;
        }
        vector<vector<char>> v(numRows);
        int row = 0;
        int flag = 1; // 正负系数
        for (int i = 0; i < s.size(); i++)
        {
            v[row].push_back(s[i]);
            row += flag;
            if (row == numRows - 1)
            {
                flag = -1;
            }
            if (row == 0)
            {
                flag = 1;
            }
        }
        string ret = "";
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v[i].size(); j++)
            {
                ret += v[i][j];
            }
        }
        return ret;
    }
};

int main()
{
    Solution *s = new Solution();
    string ret = s->convert("PAYPALISHIRING", 3);
    return 0;
}