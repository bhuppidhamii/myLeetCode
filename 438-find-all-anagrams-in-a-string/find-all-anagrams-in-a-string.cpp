class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size();
        int k = p.size();

        map<char, int> mp1, mp2;
        for (int i = 0; i < k - 1; i++) {
            mp1[s[i]]++;
        }

        for (auto& ch : p) {
            mp2[ch]++;
        }

        int idx = 0;
        for (int i = k - 1; i < n; i++) {

            char ch = s[i];
            // add
            mp1[ch]++;

            if (mp1 == mp2) {
                ans.push_back(idx);
            }

            // remove
            if (mp1[s[idx]] == 1) {
                mp1.erase(s[idx]);
            } else {
                mp1[s[idx]]--;
            }
            idx++;
        }
        return ans;
    }
};