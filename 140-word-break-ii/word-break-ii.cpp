class Solution {
public:
    void solve(int i, string &s, unordered_set<string>&st, unordered_set<string>&ans, string temp){
        if(i >= s.size()){
            temp.pop_back();
            ans.insert(temp);
            return;
        }

        // if(st.find(s)!=st.end()) return true;

        for(int l=1; l<=s.size(); l++){
            string str = s.substr(i, l);
            if(st.find(str) != st.end()){
                solve(i+l, s, st, ans, temp+str+" ");
            }
        }
    }
    vector<string> wordBreak(string &s, vector<string>& dict) {
        unordered_set<string>ans;
        unordered_set<string>st(dict.begin(), dict.end());
        solve(0, s, st, ans, "");

        vector<string>res;
        for(auto &i:ans){
            res.push_back(i);
        }
        return res;
    }
};