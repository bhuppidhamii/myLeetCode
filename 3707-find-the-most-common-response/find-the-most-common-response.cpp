class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        map<string, int> mp;
        for (auto& arr : responses) {
            // store all unique responses in a set
            set<string> st;
            for (auto& r : arr) {
                st.insert(r);
            }

            // store that all unique responses in map
            for (auto& i : st) {
                mp[i]++;
            }
        }
        int max_freq = -1;
        string ans = "";
        for (auto i : mp) {
            if (i.second == max_freq) {
                // lexicographically smaller
                ans = min(ans, i.first);
            } else if (i.second > max_freq) {
                max_freq = i.second;
                ans = i.first;
            }
        }
        return ans;
    }
};