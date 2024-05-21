class Solution {
public:
    void solve(string& s, int i, string temp, vector<string>& ans) {
        if (i >= s.size()) {
            ans.push_back(temp);
            return;
        }

        // if character
        if (s[i] >= 'a' && s[i] <= 'z' || s[i]>='A' && s[i]<='Z') {
            // lowercase
            char lwr=tolower(s[i]);
            temp+=lwr;
            solve(s, i + 1, temp, ans);

            // uppercase
            temp.pop_back();
            char uppr = toupper(s[i]);
            temp += uppr;
            solve(s, i + 1, temp, ans);
        } else {
            temp += s[i];
            solve(s, i + 1, temp, ans);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string temp = "";
        solve(s, 0, temp, ans);
        return ans;
    }
};