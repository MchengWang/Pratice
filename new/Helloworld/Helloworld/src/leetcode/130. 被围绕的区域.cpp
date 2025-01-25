#include <vector>

class Solution {
public:
    void solve(std::vector<std::vector<char>>& board) {
        if ((rows = board.size()) == 0) 
            return;

        cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            dfs(board, i, 0);
            dfs(board, i, cols - 1);
        }

        for (int i = 1; i < cols - 1; i++) {
            dfs(board, 0, i);
            dfs(board, rows - 1, i);
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) 
                if (board[i][j] == 'W') 
                    board[i][j] = 'O';
                else if (board[i][j] == 'O') 
                    board[i][j] = 'X';
        }
    }

private:
    int rows, cols;

    void dfs(std::vector<std::vector<char>>& board, int x, int y) {
        if (x < 0 || x >= rows || y < 0 || y >= cols || board[x][y] != 'O') 
            return;

        board[x][y] = 'W';
        dfs(board, x + 1, y);
        dfs(board, x - 1, y);
        dfs(board, x, y + 1);
        dfs(board, x, y - 1);
    }
};