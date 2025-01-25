#include <string>

class Solution {
public:
    int titleToNumber(std::string columnTitle) {
        int sum = 0;
        for (int i = 0; i < columnTitle.size(); ++i) {
            sum *= 26;
            sum += (int)(columnTitle[i] % 65) + 1;
        }
        return sum;
    }
};