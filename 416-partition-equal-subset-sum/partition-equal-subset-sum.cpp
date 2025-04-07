class Solution {
public:
    int N, sum;
    int t[200][20001];
    bool solve(int i, vector<int>& nums, int currSum) {
        if (i >= N) {
            return currSum == sum / 2;
        }
        if(t[i][currSum]!=-1){
            return false;
        }

        // take
        if (solve(i + 1, nums, nums[i] + currSum)) {
            return t[i][currSum]= true;
        }

        // not take
        if (solve(i + 1, nums, currSum)) {
            return t[i][currSum]=true;
        }

        return t[i][currSum]=false;
    }
    bool canPartition(vector<int>& nums) {
        N = nums.size();
        sum = 0;

        for (auto& n : nums) {
            sum += n;
        }

        if (sum % 2 != 0) {
            return false;
        }
        memset(t, -1, sizeof(t));

        return solve(0, nums, 0);
    }
};