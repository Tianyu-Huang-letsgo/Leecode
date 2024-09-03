#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// 岛屿的最大面积
class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int ret = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    ret = max(dfs(grid, i, j, 0), ret);
                }
            }
        }
        return ret;
    }

private:
    // 返回当前计算最大面积, 状态包含计数
    int dfs(vector<vector<int>> &grid, int r, int c, int cnt)
    {
        if (!inArea(grid, r, c) || grid[r][c] != 1)
        {
            return 0;
        }
        cnt = cnt + 1;
        grid[r][c] = 2; // 记得更新图表！！
        cnt = max(dfs(grid, r + 1, c, cnt), cnt);
        cnt = max(dfs(grid, r - 1, c, cnt), cnt);
        cnt = max(dfs(grid, r, c + 1, cnt), cnt);
        cnt = max(dfs(grid, r, c - 1, cnt), cnt);
        return cnt;
    }

    bool inArea(const vector<vector<int>> &grid, int r, int c)
    {
        return r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size();
    }
};

// 时间更优解：
// 思路与计算周长是一样的
class Solution2
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int ret = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (isvalid(grid, i, j))
                    ret = max(ret, find(grid, i, j));
            }
        }
        return ret;
    }

    int find(vector<vector<int>> &grid, int i, int j)
    {
        if (!isvalid(grid, i, j))
            return 0;
        grid[i][j] = 2;
        return 1 + find(grid, i + 1, j) + find(grid, i, j + 1) + find(grid, i - 1, j) + find(grid, i, j - 1);
    }

    bool isvalid(vector<vector<int>> &grid, int i, int j)
    {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1;
    }
};

int main()
{

    return 0;
}