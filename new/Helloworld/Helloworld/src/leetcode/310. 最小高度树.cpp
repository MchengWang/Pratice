#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>>& edges) {
        // 如果 n 为 1，这说明树只有根节点
        if (n == 1) return { 0 };

        // 定义节点度数数组, 并将数组的大小初始化为 n
        std::vector<int> degree(n);
        // 定义一个邻接矩阵，存储点与点之间的边
        std::vector<std::vector<int>> adjMatrix(n);
        // 将点与点的边记录到矩阵中
        for (auto& edge : edges)
        {
            // 在数组中点与点的关系是 [0,1] 则可以知道两条矩阵信息 0-1 1-0
            adjMatrix[edge[0]].emplace_back(edge[1]);
            adjMatrix[edge[1]].emplace_back(edge[0]);
            // 计算各个点的度数
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        // 定义一个队列，存储度数为 1 的顶点
        std::queue<int> queue;
        // 定义一个结果数组
        std::vector<int> result;

        // 将度数数组中度数为 1 的点存进队列中
        for (int i = 0; i < degree.size(); i++)
            if (degree[i] == 1) queue.emplace(i);

        int node = n;

        while (node > 2)
        {
            int len = queue.size();
            node -= len;
            for (int i = 0; i < len; i++)
            {
               // 取队列中头元素
                int curr = queue.front();
                // 移动队列指针，到其的下一个位置
                queue.pop();
                // 遍历矩阵
                for (auto& matrix : adjMatrix[curr])
                    if (--degree[matrix] == 1) queue.emplace(matrix);
            }
        }

        while (!queue.empty())
        {
            result.emplace_back(queue.front());
            queue.pop();
        }

        return result;
    }
};