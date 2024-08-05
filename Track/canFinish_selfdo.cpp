#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

#include <vector>
#include <queue>
#include <iostream>

class Solution
{
public:
    // 入度表
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> inDegrees(numCourses, 0);     // 入度表
        vector<vector<int>> ajacency(numCourses); // 拓扑排序邻接表
        queue<int> q;

        // 更新入度表与邻接表
        for (auto prer : prerequisites)
        {
            int pre = prer[1];
            int cur = prer[0];
            inDegrees[cur]++;
            ajacency[pre].push_back(cur);
        }

        // 拓扑排序步骤：度为0的点推进队列
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
            for (int j : ajacency[pre])
            {
                if (--inDegrees[j] == 0) // 删除节点的有向边，将入度为0的节点推进队列
                    q.push(j);
            }
            numCourses--; // 如果有环，就不能将课程数完全删除
        }

        return numCourses == 0;
    }
};

int main()
{
    Solution solution;
    std::vector<std::vector<int>> prerequisites = {{1, 0}, {0, 1}};
    int numCourses = 2;
    bool result = solution.canFinish(numCourses, prerequisites);
    std::cout << "Can finish all courses: " << (result ? "Yes" : "No") << std::endl;
    return 0;
}
