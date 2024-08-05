#include <vector>
#include <iostream>

class Solution
{
public:
    // bool型dfs，直接返回正确与否判断
    bool dfs(int i, std::vector<std::vector<int>> &adjacency, std::vector<int> &flags)
    {
        // 返回条件，1. 碰到已经访问过且子树无环的节点；2. 重复访问的节点（false）
        if (flags[i] == -1)
            return true; // 已经访问过，并且子树中没有环
        if (flags[i] == 1)
            return false; // 在当前DFS路径中重复访问，表明有环
        flags[i] = 1;     // 标记当前节点正在访问
        // 遍历当前节点的所有子树
        for (int j : adjacency[i])
        {
            if (!dfs(j, adjacency, flags))
                return false;
        }
        flags[i] = -1; // 标记当前节点访问完成，且子树中无环
        return true;
    }

    bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites)
    {
        std::vector<std::vector<int>> adjacency(numCourses);
        std::vector<int> flags(numCourses, 0);
        for (const auto &pair : prerequisites)
        {
            adjacency[pair[1]].push_back(pair[0]); // 构建邻接表
        }
        for (int i = 0; i < numCourses; ++i)
        {
            if (!dfs(i, adjacency, flags))
                return false; // 如果发现环，则不能完成所有课程
        }
        return true;
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
