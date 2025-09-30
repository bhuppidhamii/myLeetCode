class Solution {
  public:
    void solve(int n, vector<string>&ans, string temp){
        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }
        
        for(char ch='0'; ch<='1'; ch++){
            temp+=ch;
            solve(n, ans, temp);
            temp.pop_back();
        }
    }
    vector<string> binstr(int n) {
        // Jai Shri Ram
    
        vector<string>ans;
        solve(n, ans, "");
        
        return ans;
    }
};