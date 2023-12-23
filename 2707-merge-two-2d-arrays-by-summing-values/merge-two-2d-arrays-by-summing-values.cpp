class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> m;
        for (auto& i : nums1) {
            int key = i[0];
            int val = i[1];
            if (m.find(key) == m.end()) {
                m.insert({key, val});
            }
        }
        for (auto& i : nums2) {
            int key = i[0];
            int val = i[1];
            if (m.find(key) != m.end()) {
                // already present
                int v = m[key];
                m.erase(key);
                v += val;
                m.insert({key, v});
            } else {
                m.insert({key, val});
            }
        }
        vector<vector<int>> ans;
        for (auto i : m) {
            ans.push_back({i.first, i.second});
        }
        return ans;
    }
};