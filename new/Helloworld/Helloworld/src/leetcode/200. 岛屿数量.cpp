#include <vector>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int rows = grid.size();
        if (!rows) return 0;

        int cols = grid[0].size();

        int count = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == '1')
                {
                    ++count;
                    dfs(grid, i, j);
                }
            }
        }

        return count;
    }

private:
    void dfs(std::vector<std::vector<char>>& grid, int row, int col)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        grid[row][col] = '0';
        if (row - 1 >= 0 && grid[row - 1][col] == '1') dfs(grid, row - 1, col);
        if (row + 1 < rows && grid[row + 1][col] == '1') dfs(grid, row + 1, col);
        if (col - 1 >= 0 && grid[row][col - 1] == '1') dfs(grid, row, col - 1);
        if (col + 1 < cols && grid[row][col + 1] == '1') dfs(grid, row, col + 1);
    }
};