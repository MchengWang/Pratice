#include <vector>
#include <algorithm>

class Solution {
public:
    int minFlips(std::vector<std::vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        std::vector<int> f(4, INT_MAX / 2);
        f[0] = 0;
        for (int i = 0; i < (m + 1) / 2; i++) {
            for (int j = 0; j < (n + 1) / 2; j++) {
                int ones = grid[i][j], cnt = 1;
                if (j != n - 1 - j) {
                    ones += grid[i][n - 1 - j];
                    cnt++;
                }
                if (i != m - 1 - i) {
                    ones += grid[m - 1 - i][j];
                    cnt++;
                }
                if (i != m - 1 - i && j != n - 1 - j) {
                    ones += grid[m - 1 - i][n - 1 - j];
                    cnt++;
                }
                // 将这一组全部变成 1 的代价
                int cnt1 = cnt - ones;
                // 将这一组全部变成 0 的代价
                int cnt0 = ones;
                std::vector<int> tmp(4);
                for (int k = 0; k < 4; k++) {
                    tmp[k] = f[k] + cnt0;
                }
                for (int k = 0; k < 4; k++) {
                    tmp[(k + cnt) % 4] = std::min(tmp[(k + cnt) % 4], f[k] + cnt1);
                }
                swap(f, tmp);
            }
        }
        return f[0];
    }
};