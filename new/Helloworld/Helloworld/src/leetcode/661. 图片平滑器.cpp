#include <vector>
#include <algorithm>

class Solution {
public:
   std::vector<std::vector<int>> imageSmoother(std::vector<std::vector<int>>& img) {
        int m = img.size(), n = img[0].size();

        std::vector<std::vector<int>> nums(m + 1, std::vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                nums[i + 1][j + 1] = nums[i + 1][j] + nums[i][j + 1] - nums[i][j] + img[i][j];
            }
        }

        std::vector<std::vector<int>> result(m, std::vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int xl = std::max(i - 1, 0), yu = std::max(j - 1, 0); // x_left y-up
                int xr = std::min(i + 2, m), yd = std::min(j + 2, n); // x_right y_down

                int cul = (yd - yu) * (xr - xl);

                result[i][j] = (nums[xr][yd] - nums[xr][yu] - nums[xl][yd] + nums[xl][yu]) / cul;
            }
        }
        return result;
    }
};