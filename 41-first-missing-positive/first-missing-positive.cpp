class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int N = nums.size();
        vector<int> v(100001, 0);
        for (auto& i : nums) {
            if (i > 0 && i <= 100000) {
                v[i]++;
            }
        }
        for (int i = 1; i < 100001; i++) {
            if (v[i] == 0) {
                return i;
            }
        }
        return N + 1;
    }
};