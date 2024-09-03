#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    // 入度表
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> inDegrees(numCourses, 0);     // 入度表：统计每个节点入度数量
        vector<vector<int>> ajacency(numCourses); // 二维数组作拓扑排序邻接表：有向表，pre->cur（所有对应的）
        queue<int> q;                             // 存储度为0的点

        // 更新入度表与邻接表
        for (auto prer : prerequisites)
        {
            int pre = prer[1];
            int cur = prer[0];
            inDegrees[cur]++;
            ajacency[pre].push_back(cur);
        }

        // 拓扑排序步骤：入度为0的点推进队列
        for (int i = 0; i < numCourses; i++)
        {
            if (inDegrees[i] == 0)
            {
                q.push(i);
            }
        }

        // 开始拓扑排序遍历
        while (!q.empty())
        {
            int pre = q.front();
            q.pop();
            for (int j : ajacency[pre]) // 遍历当前课程后继结点
            {
                if (--inDegrees[j] == 0) // 删除节点的有向边，将入度为0的节点推进队列
                    q.push(j);
            }
            numCourses--;
        }

        return numCourses == 0;
    }
};

int main()
{
    return 0;
}