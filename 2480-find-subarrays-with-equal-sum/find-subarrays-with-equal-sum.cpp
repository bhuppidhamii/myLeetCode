class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        map<int, int> m;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            int sum = nums[i] + nums[i + 1];
            if (m.find(sum) != m.end()) {
                return true;
            } else {
                m[sum]++;
            }
        }
        return false;
    }
};