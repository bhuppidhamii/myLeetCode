class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;

        for (auto s : strs) {
            vector<int> v(26, 0);
            for (auto ch : s) {
                v[ch - 'a']++;
            }
            string temp = "";
            for (int i = 0; i < 26; i++) {
                if (v[i] >= 1) {
                    for (int j = 0; j < v[i]; j++) {
                        temp += 'a' + i;
                    }
                }
            }
            m[temp].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto i : m) {
            ans.push_back(i.second);
        }

        return ans;
    }
};