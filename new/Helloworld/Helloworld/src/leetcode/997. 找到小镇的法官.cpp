#include <iostream>
#include <vector>

class Solution {
public:
    int findJudge(int n, std::vector<std::vector<int>>& trust) {
        std::vector<int> inDegrees(n + 1);
        std::vector<int> outDegrees(n + 1);

        for (auto& edge : trust) {
            int x = edge[0], y = edge[1];
            ++inDegrees[y];
            ++outDegrees[x];
        }

        for (int i = 1; i <= n; ++i) 
            if (inDegrees[i] == n - 1 && outDegrees[i] == 0) 
                return i;
        
        return -1;
    }
};

int main1()
{
    std::vector<std::vector<int>> vecs = { { 1, 3 }, { 2, 3 }, { 3, 1 } };
    Solution sol;
    std::cout << sol.findJudge(3, vecs);
    return 0;
}