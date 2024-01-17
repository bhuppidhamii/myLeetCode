class Solution {
public:
    bool checkFreq(string& s) {
        vector<int> freq(26);
        for (auto ch : s) {
            freq[ch - 'a']++;

            if (freq[ch - 'a'] > 1) {
                return true;
            }
        }
        return false;
    }
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length())
            return false;

        if (s == goal) {
            return checkFreq(s);
        } else {
            vector<int> idx;
            for (int i = 0; i < s.length(); i++) {
                if (s[i] != goal[i]) {
                    idx.push_back(i);
                }
            }
            if (idx.size() == 2) {
                swap(s[idx[0]], s[idx[1]]);
                if (s == goal) {
                    return true;
                }
            }
        }
        return false;
    }
};