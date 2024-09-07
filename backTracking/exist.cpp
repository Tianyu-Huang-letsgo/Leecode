#include <vector>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

// 更优解法
class Solution
{
public:
    // 思路：做一个dfs，右下左上遍历
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }

private:
    // k表示单词位数
    bool dfs(vector<vector<char>> &board, const string target, int i, int j, int k)
    {
        // 核心点：board[i][j] != target[k]就return false， 只要有一个字母对不上，那就是错误路径，返回寻找更优路径，终极剪枝思想
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != target[k])
        {
            return false;
        }

        if (k == target.size() - 1)
        {
            return true;
        }

        board[i][j] = '\0';
        // 诗一样的代码
        bool ret = dfs(board, target, i + 1, j, k + 1) || dfs(board, target, i, j + 1, k + 1) || dfs(board, target, i - 1, j, k + 1) || dfs(board, target, i, j - 1, k + 1);
        board[i][j] = target[k];
        return ret;
    }
};

// 缺点：平均时间复杂度较高
class Solution2
{
public:
    // 思路：做一个dfs，右下左上遍历
    bool exist(vector<vector<char>> &board, string word)
    {
        string s = "";
        vector<vector<bool>> isTracking(board.size(), vector<bool>(board[0].size(), 0));
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                dfs(board, word, s, i, j, isTracking);
            }
        }
        return this->ret_;
    }

private:
    bool ret_ = false;
    void dfs(const vector<vector<char>> &board, const string target, string &str_tmp, int i, int j, vector<vector<bool>> &isTracking)
    {
        if (ret_ == true || str_tmp.size() >= target.size())
        {
            return;
        }
        if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0)
        {
            return;
        }
        if (isTracking[i][j] == 1)
        {
            return;
        }

        str_tmp += board[i][j];
        if (str_tmp == target)
        {
            ret_ = true;
            return;
        }
        isTracking[i][j] = 1;
        dfs(board, target, str_tmp, i, j + 1, isTracking);
        dfs(board, target, str_tmp, i + 1, j, isTracking);
        dfs(board, target, str_tmp, i, j - 1, isTracking);
        dfs(board, target, str_tmp, i - 1, j, isTracking);
        isTracking[i][j] = 0;
        str_tmp.pop_back();
    }
};

int main()
{
    Solution *s = new Solution();
    std::vector<std::vector<char>> b1 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    vector<vector<char>> b2 = {{'A', 'B', 'C', 'E'},
                               {'S', 'F', 'C', 'S'},
                               {'A', 'D', 'E', 'E'}};
    vector<vector<char>> b3 = {{'a'}};

    string w1 = "ABCCED";
    string w2 = "SEEM";
    string w3 = "a";

    bool ret = s->exist(b2, w2);
    return 0;
}