class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        for (auto s : strs) {
            string str2 = s;
            sort(str2.begin(), str2.end());
            m[str2].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto i : m) {
            ans.push_back(i.second);
        }
        return ans;
    }
};