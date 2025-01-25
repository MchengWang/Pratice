#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    std::vector<int> smallestRange(std::vector<std::vector<int>>& nums) {
        int left = 0, right = INT_MAX;

        int size = nums.size();
        std::vector<int> next(size);

        auto cmp = [&](const int& u, const int& v) {
            return nums[u][next[u]] > nums[v][next[v]];
            };

        std::priority_queue<int, std::vector<int>, decltype(cmp)> pq(cmp);

        int min = 0, max = INT_MIN;
        for (int i = 0; i < size; ++i) {
            pq.emplace(i);
            max = std::max(max, nums[i][0]);
        }

        while (true) {
            int row = pq.top();
            pq.pop();
            min = nums[row][next[row]];
            if (max - min < right - left) {
                left = min;
                right = max;
            }
            if (next[row] == nums[row].size() - 1) {
                break;
            }
            ++next[row];
            max = std::max(max, nums[row][next[row]]);
            pq.emplace(row);
        }

        return { left, right };
    }
};