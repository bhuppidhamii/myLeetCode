class Solution {
  public:
    int N1, N2;
    int solve(string &s1, string &s2, int i, int j, vector<vector<int>>&t){
        if(i >= N1 || j >= N2){
            return 0;
        }
        
        if(t[i][j] != -1){
            return t[i][j];
        }
        
        // if chars are same ---
        if(s1[i] == s2[j]){
            return t[i][j] = 1 + solve(s1, s2, i+1, j+1, t);
        }
        
        // if chars are not same ---
        int move_i=solve(s1, s2, i+1, j, t);
        int move_j=solve(s1, s2, i, j+1, t);
        
        return t[i][j] = max(move_i, move_j);
    }
    int lcs(string &s1, string &s2) {
        // code here
        N1=s1.size();
        N2=s2.size();
        vector<vector<int>>t(N1+1, vector<int>(N2+1, -1));
        return solve(s1, s2, 0, 0, t);
    }
};
