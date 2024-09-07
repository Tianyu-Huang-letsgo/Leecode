#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        if (n == 1)
        {
            return {{"Q"}};
        }
        vector<string> chess(n, string(n, '.'));
        vector<pair<int, int>> cods;
        dfs(chess, 0, n, cods);
        return ret_;
    }

private:
    void dfs(vector<string> &chess, int row, const int n, vector<pair<int, int>> &cods)
    {
        if (row == n)
        {
            ret_.push_back(chess);
            return;
        }
        for (int i = 0; i < n; i++) // i作为列， n作为行遍历
        {
            if (isValid(cods, make_pair(row, i)))
            {
                cods.push_back(make_pair(row, i));
                // assert(n >= 0 && n < 4 && i >= 0 && i < 4);
                chess[row][i] = 'Q';
                dfs(chess, row + 1, n, cods);
                chess[row][i] = '.';
                cods.pop_back();
            }
        }
    }

    bool isValid(const vector<pair<int, int>> &cods, const pair<int, int> &cur_cod)
    {
        for (auto cod : cods)
        {
            if (cod.first == cur_cod.first || cod.second == cur_cod.second ||
                abs(cod.first - cur_cod.first) == abs(cod.second - cur_cod.second))
            {
                return false;
            }
        }
        return true;
    }

private:
    vector<vector<string>> ret_;
    vector<pair<int, int>> cod_; // 存放已有坐标点
};

int main()
{
    Solution *s = new Solution();
    vector<vector<string>> ret = s->solveNQueens(8);
    return 0;
}