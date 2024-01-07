class Solution {
public:
    int missingInteger(vector<int>& nums) {
        map<int, int> m;
        for (auto i : nums) {
            m[i]++;
        }

        int j = 1, sum = nums[0], n = nums.size();
        while (j < n && nums[j] == nums[j - 1] + 1) {
            sum += nums[j];
            j++;
        }

        while (m.find(sum) != m.end()) {
            sum++;
        }
        return sum;
    }
};