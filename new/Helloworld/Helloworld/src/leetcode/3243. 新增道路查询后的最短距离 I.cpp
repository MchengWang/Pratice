#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> shortestDistanceAfterQueries(int n, std::vector<std::vector<int>>& queries) {
        std::vector<std::vector<int>> prev(n);
        std::vector<int> dp(n);
        for (int i = 1; i < n; i++) {
            prev[i].push_back(i - 1);
            dp[i] = i;
        }
        std::vector<int> res;
        for (auto& query : queries) {
            prev[query[1]].push_back(query[0]);
            for (int v = query[1]; v < n; v++) {
                for (int u : prev[v]) {
                    dp[v] = std::min(dp[v], dp[u] + 1);
                }
            }
            res.push_back(dp[n - 1]);
        }
        return res;
    }
};