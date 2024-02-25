class Solution {
public:
    long long int solve(int idx, vector<int>& nums, vector<int>& t) {
        if (idx == nums.size() - 1)
            return 0;
        if (t[idx] != -1) {
            return t[idx];
        }
        long long int minJumps = INT_MAX;
        for (int i = 1; i <= nums[idx] && i + idx < nums.size(); i++) {
            minJumps = min(minJumps, 1 + solve(i + idx, nums, t));
            t[idx] = minJumps;
        }
        return t[idx] = minJumps;
    }
    int jump(vector<int>& nums) {
        vector<int> t(10001, -1);
        return solve(0, nums, t);
    }
};