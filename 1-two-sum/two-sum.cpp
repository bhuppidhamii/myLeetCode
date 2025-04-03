class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int N = nums.size();

        vector<int> ans;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (nums[i] + nums[j] == target) {
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};