class Solution {
  public:
    string URLify(string &s) {
        // Jai Shri Ram
        string ans="";
        for(int i=0; i<s.size(); i++){
            if(s[i] == ' '){
                ans+="%20";
            }else{
                ans+=s[i];
            }
        }
        return ans;
    }
};