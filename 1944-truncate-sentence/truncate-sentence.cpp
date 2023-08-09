class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans="";
        int N=s.length();
        for(int i=0;i<N;i++){
            if(s[i] == ' ') k--;
            if(k == 0) break;
            ans.push_back(s[i]);
        }
        return ans;
    }
};