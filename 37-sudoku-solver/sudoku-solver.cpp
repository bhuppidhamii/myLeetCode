class Solution {
public:
    bool isValid(vector<vector<char>>& board, int r, int c, char n) {
        // row validity
        for (int i = 0; i < 9; i++) {
            if (board[r][i] == n)
                return false;
        }

        // column validity
        for (int i = 0; i < 9; i++) {
            if (board[i][c] == n)
                return false;
        }

        // 3x3 box validity
        int start_r = r / 3 * 3;
        int start_c = c / 3 * 3;
        for (int i = start_r; i < start_r + 3; i++) {
            for (int j = start_c; j < start_c + 3; j++) {
                if (board[i][j] == n)
                    return false;
            }
        }

        // not found
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.') {

                    for (char d = '1'; d <= '9'; d++) {
                        if (isValid(board, i, j, d) == true) {
                            board[i][j] = d; // do

                            if (solve(board) == true) { // explore
                                return true;
                            }

                            board[i][j] = '.'; // undo
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) { solve(board); }
};