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
        vector<int> indegrees(numCourses, 0);      // 用于存储每个课程的入度
        vector<vector<int>> adjacency(numCourses); // 用于存储每一个课程的后续课程
        queue<int> queue;                          // 用于BFS的课程队列

        // 获取每个课程的入度和邻接课程列表
        for (const auto &pair : prerequisites)
        {
            int cur = pair[0];
            int pre = pair[1];
            indegrees[cur]++;
            adjacency[pre].push_back(cur);
        }

        // 将所有入度为0的课程加入队列
        for (int i = 0; i < numCourses; ++i)
        {
            if (indegrees[i] == 0)
            {
                queue.push(i);
            }
        }

        // BFS拓扑排序
        while (!queue.empty())
        {
            int pre = queue.front();
            queue.pop();
            numCourses--;
            for (int cur : adjacency[pre])
            {
                if (--indegrees[cur] == 0)
                {
                    queue.push(cur);
                }
            }
        }

        // 如果还有课程没有被访问，则存在环
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

int main()
{
    return 0;
}