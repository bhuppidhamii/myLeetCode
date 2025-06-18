class Solution {
public:
    int N;
    bool checkPalindrome(string& s) {
        int i = 0, j = s.size()-1;
        while (i <= j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(string& s, int idx, vector<string>& curr, vector<vector<string>>& ans) {
        if (idx >= N) {
            ans.push_back(curr);
            return;
        }
        for (int i = idx; i < N; i++) {
            int len = (i-idx) + 1;
            string sub = s.substr(idx, len);
            if (checkPalindrome(sub)) {
                curr.push_back(sub);
                solve(s, i+1, curr, ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        N = s.size();
        vector<vector<string>> ans;
        vector<string> curr;
        solve(s, 0, curr, ans);
        return ans;
    }
};