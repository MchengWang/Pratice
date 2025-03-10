﻿#include <vector>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int size = matrix.size();
        for (int i = 0; i < size / 2; i++)
        {
            for (int j = 0; j < (size + 1) / 2; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[size - j - 1][i];
                matrix[size - j - 1][i] = matrix[size - i - 1][size - j - 1];
                matrix[size - i - 1][size - j - 1] = matrix[j][size - i - 1];
                matrix[j][size - i - 1] = temp;
            }
        }
    }
};