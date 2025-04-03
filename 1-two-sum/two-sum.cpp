class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        int N = nums.size();

        for (int i = 0; i < N; i++) {

            if (mp.find(target - nums[i]) != mp.end()) {
                return {mp[target - nums[i]], i};
            } else {
                mp[nums[i]] = i;
            }
        }
        return {};
    }
};