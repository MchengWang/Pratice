// 可以认为使求解拓扑排序
#include <iostream>

#include <vector>
#include <stack>

class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);

        for (std::vector<int>& vec : prerequisites)
        {
            edges[vec[1]].push_back(vec[0]);
        }

        for (int i = 0; i < numCourses && valid; ++i)
        {
            if (!visited[i])
            {
                dfs(i);
            }
        }

        return valid;
    }

    void dfs(int n)
    {
        // 如果标记数组不为空
        visited[n] = 1;
        for (int i : edges[n])
        {
            if (visited[i] == 0)
            {
                dfs(i);
                if (!valid)
                {
                    return;
                }
            }
            else if (visited[i] == 1)
            {
                valid = false;
                return;
            }
        }

        visited[n] = 2;
    }

public:
    std::vector<int> visited;
    std::vector<std::vector<int>> edges;

    bool valid = true;
};