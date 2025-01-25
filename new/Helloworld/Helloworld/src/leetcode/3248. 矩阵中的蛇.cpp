#include <string>
#include <vector>

class Solution {
public:
    int finalPositionOfSnake(int n, std::vector<std::string>& commands) {
        int ans = 0;

        for (const std::string& str : commands) {
            switch (str[0])
            {
            case 'U': ans -= n; break;
            case 'D': ans += n; break;
            case 'L': --ans;    break;
            case 'R': ++ans;    break;
            }
        }

        return ans;
    }
};