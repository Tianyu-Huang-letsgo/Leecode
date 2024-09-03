#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

// 腐烂的橘子
// 岛屿问题的变种
// 思路：多源广度遍历
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int cnt = 0;                  // 新鲜橘子数量
        int badTime[10][10];          // 记录腐坏时间
        int dis_x[4] = {0, 1, 0, -1}; // 左下右上
        int dis_y[4] = {-1, 0, 1, 0};
        int ans = 0;

        memset(badTime, -1, sizeof(badTime)); // memset()用于统一设置以字节为单位的空间，设置0，-1时不会出错
        queue<pair<int, int>> q;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push(make_pair(i, j)); // q.emplace(i, j)
                    badTime[i][j] = 0;       // 记录所有腐烂橘子（多源）
                }
                else if (grid[i][j] == 1)
                    ++cnt;
            }
        }
        // bfs
        while (!q.empty())
        {
            pair<int, int> cur_ori = q.front();
            q.pop();
            // bfs是每个节点遍历周围节点进行处理
            for (int i = 0; i < 4; i++)
            {
                int dx = dis_x[i] + cur_ori.first;
                int dy = dis_y[i] + cur_ori.second;
                // 当前点越界、为空位、已经遍历过了（时间被赋值过）,都跳过
                if (dx < 0 || dx >= grid.size() || dy < 0 || dy >= grid[0].size() || grid[dx][dy] == 0 || badTime[dx][dy] != -1)
                {
                    continue;
                }

                // 接下来是处理合法值（新鲜水果）
                // **这个值是根据对应污染源刷新的**
                badTime[dx][dy] = badTime[cur_ori.first][cur_ori.second] + 1; // badTime被赋值就相当于已经腐烂了
                q.emplace(dx, dy);
                // 这个判断是可以舍去的，这里只是为了阅读清晰
                if (grid[dx][dy] == 1)
                {
                    ans = badTime[dx][dy]; // 这个值不断刷新，一定是最大的
                    if (--cnt == 0)
                        break;
                }
            }
        }
        return cnt == 0 ? ans : -1;
    }
};

int main()
{
    return 0;
}