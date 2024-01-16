class Solution {
public:
    unordered_map<int, vector<int>> m;
    vector<int> v;
    Solution(vector<int>& nums) {
        for (auto i : nums) {
            v.push_back(i);
            m[i].push_back(v.size() - 1);
        }
    }

    int pick(int target) {
        vector<int> ans = m[target];
        if (ans.size() == 1) {
            return m[target][0];
        } else {
            int idx = rand() % ans.size();
            return ans[idx];
        }
    }
};