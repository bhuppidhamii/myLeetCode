class Solution {
public:
    int n;
    int t[10001];
    long long int solve(int idx, vector<int>& nums) {
        if (idx == n - 1)
            return 0;
        if (idx >= n)
            return 99;
        if (t[idx] != -1) {
            return t[idx];
        }
        long long int minJumps = INT_MAX;
        for (int i = 1; i <= nums[idx]; i++) {
            minJumps = min(minJumps, 1 + solve(i + idx, nums));
            t[idx] = minJumps;
        }
        return t[idx] = minJumps;
    }
    int jump(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        n = nums.size();
        return solve(0, nums);
    }
};