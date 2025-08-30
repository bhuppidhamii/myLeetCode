class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // validate rows
        for (int row = 0; row < 9; row++) {
            unordered_set<char> st;
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') continue;
                if (st.find(board[row][col]) != st.end()) {
                    return false;
                }
                st.insert(board[row][col]);
            }
        }

        // validate columns
        for (int col = 0; col < 9; col++) {
            unordered_set<char> st;
            for (int row = 0; row < 9; row++) {
                if (board[row][col] == '.') continue;
                if (st.find(board[row][col]) != st.end()) {
                    return false;
                }
                st.insert(board[row][col]);
            }
        }

        // validate 3x3 sub-boxes
        for(int row = 0; row<9; row+=3){
            for(int col = 0; col<9; col+=3){

                // each 3x3 box
                unordered_set<char> st;
                for(int i=row; i<row+3; i++){
                    for(int j=col; j<col+3; j++){
                        if (board[i][j] == '.') continue;
                        if (st.find(board[i][j]) != st.end()) {
                            return false;
                        }
                        st.insert(board[i][j]);
                    }
                }
            }
        }
        return true;
    }
};