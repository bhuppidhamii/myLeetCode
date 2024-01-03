class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int N = nums.size();
        unordered_map<int, int> m;

        vector<vector<int>> ans;
        for (auto& i : nums) {
            int freq = m[i];

            if (freq == ans.size()) {
                ans.push_back({});
            }

            ans[freq].push_back(i);
            m[i]++;
        }
        return ans;
    }
};