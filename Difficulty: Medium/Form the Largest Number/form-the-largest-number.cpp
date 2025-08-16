class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // Jai Shri Ram
        
        vector<string>v;
        for(auto &i:arr){
            v.push_back(to_string(i));
        }
        
        sort(v.begin(), v.end(),[](auto &a, auto &b){
            return a+b > b+a;
        });
        
        if(v[0] =="0") return "0";
        
        string ans="";
        for(auto &i:v){
            ans+=i;
        }
        return ans;
    }
};