class Solution {
  public:
    bool solve(string &s, int i, int j){
        if(i >= j) return true;
        // all i, j's have been equals
        
        if(s[i] == s[j]){
            return solve(s, i+1, j-1);
            // check further
        }else{
            return false;
            // s[i] != s[j]
        }
    }
    bool isPalindrome(string& s) {
        // Jai Shri Ram
        return solve(s, 0, s.size()-1);
    }
};