class Solution {
public:
    string truncateSentence(string s, int k) {
        stringstream ss(s);
        string word;
        string ans="";
        while(ss >> word && k--) {
            ans+=word;
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }

};