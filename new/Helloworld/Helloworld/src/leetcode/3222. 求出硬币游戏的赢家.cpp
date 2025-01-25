#include <string>
#include <algorithm>

class Solution {
public:
    std::string losingPlayer(int x, int y) {
        int count = std::min(x , y / 4);
        return count % 2 == 0 ? "Alice" : "Bob";
    }
};