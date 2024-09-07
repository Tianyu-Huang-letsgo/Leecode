#include <vector>
#include <stdio.h>
#include <algorithm>
#include <unordered_set>

using namespace std;

// 最大人工岛
const vector<int> d = {0, -1, 0, 1, 0};

class Solution
{
public:
    bool valid(int n, int x, int y)
    {
        return x >= 0 && x < n && y >= 0 && y < n;
    }
    // 总结：最大人工岛是最大岛屿面积的进化版
    // 1. 需要引入vector<vector<int>> tag作为标记不同岛屿,为后续海洋找不同岛屿做准备；
    // 2. 需要使用unordered_map area对每一块岛屿的面积进行记录，t作为岛屿唯一标识，每一块陆地的i,j是唯一的，刚好可以映射为t；
    // 3. 需要做两次dfs，分别得到岛屿面积与遍历海洋邻接块。
    int dfs(const vector<vector<int>> &grid, int x, int y, vector<vector<int>> &tag, int t)
    {
        int n = grid.size(), res = 1;
        tag[x][y] = t; // 标记遍历过的值，**每一个岛屿所有的t都是相同的**，tag的目的就是能区分不同岛屿
        for (int i = 0; i < 4; i++)
        {
            int x1 = x + d[i], y1 = y + d[i + 1];
            if (valid(n, x1, y1) && grid[x1][y1] == 1 && tag[x1][y1] == 0) // 位置没越界、是岛屿、没被标记过
            {
                res += dfs(grid, x1, y1, tag, t);
            }
        }
        return res;
    }

    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size(), res = 0;
        vector<vector<int>> tag(n, vector<int>(n));
        unordered_map<int, int> area;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && tag[i][j] == 0) // 当前块是陆地且还没遍历过
                {
                    int t = i * n + j + 1;             // t是从左向右，从上向下数第几个格子，作为每一块岛屿的标记值
                    area[t] = dfs(grid, i, j, tag, t); // area记录每一个岛屿的面积
                    res = max(res, area[t]);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0) // 遍历所有海洋块
                {
                    int z = 1;                    // 人工块
                    unordered_set<int> connected; // 每个海洋块邻接的陆地（防止相同）
                    for (int k = 0; k < 4; k++)
                    {
                        int x = i + d[k], y = j + d[k + 1];
                        // 这个判断是关键！！1. x,y没越界； 2. 没标记（不是陆地）； 3. 当前海洋快已经遍历过这块陆地了
                        if (!valid(n, x, y) || tag[x][y] == 0 || connected.count(tag[x][y]) > 0)
                        {
                            continue;
                        }
                        z += area[tag[x][y]];
                        connected.insert(tag[x][y]);
                    }
                    res = max(res, z);
                }
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}