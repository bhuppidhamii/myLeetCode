class Solution {
public:
    int missingNumber(vector<int>& nums) {
        map<int, int> m;
        for (auto i : nums) {
            m[i]++;
        }
        for (int i = 0; i <= nums.size(); i++) {
            if (m.find(i) == m.end()) {
                return i;
            }
        }
        return 0;
    }
};