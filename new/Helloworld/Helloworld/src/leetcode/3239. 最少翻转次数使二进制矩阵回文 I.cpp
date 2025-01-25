#include <vector>
#include <algorithm>

/* 利用两个指针，从数组的前后进行遍历，对比是否为相同元素
   如果当一行遍历完后，存在不相同的，就可以判断这一行(列)不是回文串
   而题目中问的是反转几次 0 -> 1 or 1 -> 0 能使整个矩阵都是回文串
   每次不同的时候，对其进行反转，则就可以确定回文串
*/

class Solution {
public:
    int minFlips(std::vector<std::vector<int>>& grid) {
        // 记录行，列翻转次数
        int row = 0, col = 0;

        // 获取矩阵的行数和列数
        int r = grid.size(), c = grid[0].size();

        // 遍历数组，使用双指针从行遍历，分别从数组头 和 尾 遍历，当 头尾相遇，退出循环
        for (int i = 0; i < r; i++)
            for (int front = 0, rear = c - 1; front < rear; front++, rear--)
                if (grid[i][front] ^ grid[i][rear]) row++;

        // 遍历数组，使用双指针从列遍历，分别从数组头 和 尾 遍历，当 头尾相遇，退出循环
        for (int i = 0; i < c; i++)
            for (int front = 0, rear = r - 1; front < rear; front++, rear--)
                if (grid[front][i] ^ grid[rear][i]) col++;

        // 比对行列变换的次数，求最少次数，使矩阵每一行，每一列，均为回文串
        return std::min(col, row);
    }
};