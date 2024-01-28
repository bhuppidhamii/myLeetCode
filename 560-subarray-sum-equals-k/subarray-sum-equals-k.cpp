class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> m;
        m[0] = 1; // corner-case
        int sum = 0, count = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i]; // cumulative sum
            if (m.find(sum - k) != m.end()) {
                count += m[sum - k];
            }
            m[sum]++;
        }
        return count;
    }
};