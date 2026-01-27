class Solution {
  public:
    int n, m;
    vector<vector<int>>dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    bool isInside(int i, int j){
        return(i>=0 && i<n && j>=0 && j<m);
    }
    bool check(vector<vector<char>> &mat, int i, int j, vector<vector<bool>>&visited, int idx, string &word){
        if(idx == word.size()) return true; // all words are found;
        
        // go to all dirs - top, left , bottom, right
        for(auto &d:dirs){
            int i_ = d[0]+i;
            int j_ = d[1]+j;
        
            if(isInside(i_,j_) && !visited[i_][j_] &&mat[i_][j_] == word[idx]){
                visited[i_][j_] = true;
                // cout<<i_<<", "<<j_<<"    ";
                if(check(mat, i_, j_, visited, idx+1, word)) return true;
                visited[i_][j_] = false;
            }
        }
        return false;
    }
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        // Jai Shri Ram
        
        n = mat.size(), m=mat[0].size();
        int idx=0, l = word.size();
        
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == word[idx]){
                    // start dfs
                    
                    visited[i][j] = true;
                    bool isPossible = check(mat, i, j, visited, idx+1, word);
                    if(isPossible) return true;
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};