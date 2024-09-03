#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

// 岛屿的周长
class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int ret = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    ret = dfs(grid, i, j);
                }
            }
        }
        return ret;
    }

private:
    int dfs(vector<vector<int>> &grid, int r, int c)
    {
        if (!inArea(grid, r, c))
        {
            return 0;
        }
        if (grid[r][c] != 1)
        {
            return 0;
        }
        int cnt = 0;
        grid[r][c] = 2;
        for (int i = 0; i < 4; ++i)
        {
            int dx = r + dir_x[i];
            int dy = c + dir_y[i];
            if (inArea(grid, dx, dy) && grid[dx][dy] != 0) // 注意：这里的岛屿即便是遍历过也需要算上临岛
            {
                cnt++;
            }
        }
        return 4 - cnt + dfs(grid, r + dir_x[0], c + dir_y[0]) + dfs(grid, r + dir_x[1], c + dir_y[1]) + dfs(grid, r + dir_x[2], c + dir_y[2]) + dfs(grid, r + dir_x[3], c + dir_y[3]);
    }

    bool inArea(vector<vector<int>> &grid, int r, int c)
    {
        return r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size();
    }

private:
    // 方向表
    int dir_x[4] = {1, -1, 0, 0};
    int dir_y[4] = {0, 0, 1, -1};
};

int main()
{
    vector<vector<int>> v = {{0, 1, 0, 0},
                             {1, 1, 1, 0},
                             {0, 1, 0, 0},
                             {1, 1, 0, 0}};
    Solution *s = new Solution();
    int ret = s->islandPerimeter(v);
    return 0;
}