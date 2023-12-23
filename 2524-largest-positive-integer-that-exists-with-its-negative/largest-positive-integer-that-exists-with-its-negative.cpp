class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int maxi = -1;
        map<int, int> m;
        for (auto& i : nums) {
            if (m.find(i) != m.end()) {
                maxi = max(maxi, abs(i));
                continue;
            }
            if (i > 0) {
                m[-i]++;
            } else {
                m[abs(i)]++;
            }
        }
        return maxi;
    }
};