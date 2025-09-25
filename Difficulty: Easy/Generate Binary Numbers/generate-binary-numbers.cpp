class Solution {
  public:
    string intToBinary(int n){
        string ans="";
        while(n > 0){
            int rem = n%2;
            ans = to_string(rem) + ans;
            n/=2;
        }
        return ans;
    }
    vector<string> generateBinary(int n) {
        // Jai Shri Ram
        // BF
        vector<string>ans;
        
        for(int i=1; i<=n; i++){
            ans.push_back(intToBinary(i));
        }
        return ans;
    }
};