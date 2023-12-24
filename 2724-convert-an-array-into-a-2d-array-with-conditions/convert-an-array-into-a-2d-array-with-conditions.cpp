class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int, int> m;
        for (auto i : nums) {
            m[i]++;
        }

        vector<vector<int>> ans;
        while (!m.empty()) {
            vector<int> v;
            vector<int> to_erase;

            for (auto& i : m) {
                int num = i.first;
                v.push_back(num);

                if (i.second == 1) {
                    to_erase.push_back(num);
                } else {
                    i.second--;
                }
            }

            for (int num : to_erase) {
                m.erase(num);
            }

            ans.push_back(v);
        }
        return ans;
    }
};
