#include <vector>

class Solution
{
public:
    int winningPlayerCount(int n, std::vector<std::vector<int>>& pick) {
        std::vector<std::vector<int>> cnt(n, std::vector<int>(11));
        for (auto& p : pick) {
            cnt[p[0]][p[1]]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= 10; j++) {
                if (cnt[i][j] > i) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};