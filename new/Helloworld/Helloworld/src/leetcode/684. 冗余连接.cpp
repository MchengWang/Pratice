#include <vector>

class Solution {
public:
    int Find(std::vector<int>& root, int index)
    {
        if (root[index] != index)
            root[index] = Find(root, root[index]);

        return root[index];
    }

    void Union(std::vector<int>& root, int indexl, int indexr)
    {
        root[Find(root, indexl)] = Find(root, indexr);
    }
    
    std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges) {
        std::vector<int> root(edges.size() + 1);

        for (int i = 1; i <= edges.size(); i++)
            root[i] = i;

        for (std::vector<int>& edge : edges)
        {
            int vert1 = edge[0], vert2 = edge[1];
            if (Find(root, vert1) != Find(root, vert2))
                Union(root, vert1, vert2);
            else return edge;
        }

        return std::vector<int>{};
    }
};