class Solution {
  public:
    string removeSpaces(string& s) {
        // Jai Shri Ram
        string ans = "";
        for(auto &ch:s){
            if(ch!=' '){
                ans+=ch;
            }
        }
        return ans;
    }
};