class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int N = nums.size();
        vector<int> maxLeft(N);
        maxLeft[0] = nums[0];
        for (int i = 1; i < N; i++) {
            maxLeft[i] = max(maxLeft[i - 1], nums[i]);
        }
        
        vector<int> maxRight(N);
        maxRight[N-1] = nums[N-1];
        for (int i = N-2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i + 1], nums[i]);
        }
        
        long long res = 0;
        for (int j = 1; j < N-1; j++) {
            long long val = (long long)(maxLeft[j-1] - nums[j]) * maxRight[j+1];
            res = max(res, val);
        }
        return res > 0 ? res : 0;
    }
};