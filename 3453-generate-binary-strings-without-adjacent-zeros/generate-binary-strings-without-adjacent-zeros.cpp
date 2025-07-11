class Solution {
public:
    void solve(string temp, vector<string>&all, int n){
        if(temp.size()>= n){
            all.push_back(temp);
            return;
        }

        // take 0, only if temp.last() is not 0
        if(temp.size() == 0 || (temp.size()> 0 && temp.back() != '0')){
            solve(temp+'0', all, n);
        }

        // take 1
        solve(temp+'1', all, n);
    }
    vector<string> validStrings(int n) {
        vector<string>all;
        solve("", all, n);
        return all;
    }
};