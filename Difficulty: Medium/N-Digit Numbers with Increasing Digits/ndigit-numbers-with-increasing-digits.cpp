class Solution {
  public:
    void solve(int n, vector<int>&ans, string &temp){
        if(temp.size() == n){
            // cout<<temp<<"\n";
            ans.push_back(stoi(temp));
            return;
        }
        
        for(int i=1; i<=9; i++){
            if(temp.size() != 0 && i > temp.back()-'0'){
                temp+=(i+'0');
                solve(n, ans, temp);
                temp.pop_back();
            }
            
            if(temp.size() == 0){
                temp+=(i+'0');
                solve(n, ans, temp);
                temp.pop_back();
            }
        }
    }
    vector<int> increasingNumbers(int n) {
        // Jai Shri Ram
        vector<int>ans;
        if(n == 1) ans.push_back(0);
        string temp = "";
        solve(n, ans, temp);
        return ans;
    }
};