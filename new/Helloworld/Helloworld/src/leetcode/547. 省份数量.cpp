#include <vector>

class Solution {
public:
    int findCircleNum(std::vector<std::vector<int>>& isConnected) {
        int verts = isConnected.size();
        // 定义标记数组
        std::vector<int> visited(verts);

        int count = 0;
        for (int i = 0; i < verts; i++)
        {
            if (!visited[i])
            {
                dfs(isConnected, visited, verts, i);
                count++;
            }
        }

        return count;
    }

private:
    void dfs(std::vector<std::vector<int>>& isConnected, std::vector<int>& visited, int vert, int i)
    {
        for (int j = 0; j < vert; j++)
        {
            if (isConnected[i][j] == 1 && !visited[j])
            {
                visited[j] = 1;
                dfs(isConnected, visited, vert, j);
            }
        }
    }
};