class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> arr(102, 0);
        for (int i = 0; i < nums.size(); i++) {
            arr[nums[i]]++;
        }
        vector<int> ans;
        for (int i = 0; i < 102; i++) {
            if (arr[i] > 1) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};