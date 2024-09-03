#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

// 岛屿问题归类:海洋：0，岛屿：1，遍历过的岛屿：2
// 岛屿数量
class Solution
{
public:
    // 思路：做深度遍历
    int numIslands(vector<vector<char>> &grid)
    {
        int ret = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    ++ret;
                }
            }
        }
        return ret;
    }

private:
    void dfs(vector<vector<char>> &grid, int r, int c)
    {
        if (!inArea(grid, r, c))
        {
            return;
        }
        if (grid[r][c] == '0' || grid[r][c] == '2')
        {
            return; // 海洋不进行遍历
        }
        grid[r][c] = '2';
        dfs(grid, r, c + 1);
        dfs(grid, r - 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r + 1, c);
    }

    bool inArea(const vector<vector<char>> &grid, int r, int c)
    {
        return r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size();
    }
};

int main()
{
    return 0;
}