class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        set<string>st;
        for(int i= 0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.') continue;

                string row = string(1, board[i][j]) + "ROW" + to_string(i);
                string col = string(1, board[i][j]) + "COL" + to_string(j);
                string box = string(1, board[i][j]) + "BOX" + to_string(i/3) + "_" + to_string(j/3);

                if(st.find(row) != st.end()) return false;
                st.insert(row);

                if(st.find(col) != st.end()) return false;
                st.insert(col);

                if(st.find(box) != st.end()) return false;
                st.insert(box);
            }
        }
        return true;
    }
};