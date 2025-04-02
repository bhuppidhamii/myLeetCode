class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxi = 0;
        int N = nums.size();

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                for (int k = j + 1; k < N; k++) {
                    long long res = (long long)(nums[i] - nums[j]) * nums[k];
                    maxi = max(res, maxi);
                }
            }
        }
        return maxi;
    }
};