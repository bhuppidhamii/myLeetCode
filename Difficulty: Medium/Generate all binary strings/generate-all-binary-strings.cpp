class Solution {
  public:
    void solve(string temp, vector<string>&all, int n){
        if(temp.size() >= n){
            all.push_back(temp);
            return;
        }
        
        // take 0
        solve(temp+'0', all, n);
        
        // take 1, only if temp->back is not 1
        if(temp.empty() || temp.size() > 0 && temp.back() != '1'){
            solve(temp+'1', all, n);
        }
    }
    vector<string> generateBinaryStrings(int n) {
        // Jai Shri Ram
        
        vector<string>all;
        solve("", all, n);
        return all;
    }
};