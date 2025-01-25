#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> vec;
        // 为每一个vector设置长度，并赋初值为1
        for (int i = 0; i < numRows; i++)
        {
            vec[i].resize(i + 1, 1);
        }
        // 从第二行开始，每两个进行一次相加
        for (int i = 2; i < vec.size(); i++) {
            for (int j = 1; j < vec[i].size() - 1; j++) {
                vec[i][j] = vec[i - 1][j - 1] + vec[i - 1][j];
            }
        }
        return vec;
    }
};