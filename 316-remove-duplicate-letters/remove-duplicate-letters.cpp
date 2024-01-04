class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<bool> taken(26, false);
        vector<int> lastIdx(26);
        for (int i = 0; i < n; i++) {
            int ch = s[i] - 'a';
            lastIdx[ch] = i;
        }
        string ans = "";
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            int idx = ch - 'a';

            if (taken[idx]) {
                continue;
            }
            while (ans.length() > 0 && ans.back() > ch && lastIdx[ans.back() - 'a'] > i) {
                taken[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans.push_back(ch);
            taken[idx] = true;
        }
        return ans;
    }
};