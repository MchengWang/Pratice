#include <vector>
#include <set>
#include <unordered_map>

class Solution {
public:
    std::vector<int> shortestDistanceAfterQueries(int n, std::vector<std::vector<int>>& queries) {
        // 用一个 set 维护当前的最短路包含哪些区间
        std::set<std::pair<int, int>> sp;
        // 先把初始的 i - 1 -> i 都加进来
        for (int i = 1; i < n; i++) sp.insert(std::pair<int, int>(i - 1, i));

        std::vector<int> ans;
        for (auto& query : queries) {
            int l = query[0], r = query[1];
            // 判断这个区间是否包含最短路里的其它区间
            // 如果当前最短路里存在区间 [l', r') 满足 l' == l 且 r' < r，那么新区间 [l, r) 肯定包含它
            // 否则新区间肯定已经被包含，没有加入的必要
            auto it = sp.lower_bound(std::pair<int, int>(l, -1));
            if (it != sp.end() && it->first == l && it->second < r) {
                // 踢掉所有新区间 [l, r) 包含的老区间
                while (it != sp.end() && it->first < r) it = sp.erase(it);
                sp.insert(std::pair<int, int>(l, r));
            }
            // 答案就是 set 的大小
            ans.push_back(sp.size());
        }
        return ans;
    }
};