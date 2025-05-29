class Solution {
public:
    bool canJump(vector<int>& nums) {
        int N = nums.size();
        int maxReachable = 0;

        for (int i = 0; i < N; i++) {
            if(i > maxReachable){
                return false;
            }
            maxReachable = max(maxReachable, i + nums[i]);
        }
        return true;
    }
};