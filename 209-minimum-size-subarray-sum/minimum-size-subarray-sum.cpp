class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // Jai Shri Ram
        int N=nums.size(), i=0, min_len=INT_MAX;
        int sum = 0;
    
        for(int j=0; j<N; j++){
            sum+=nums[j];

            while(i < N && sum >= target){
                min_len = min(min_len, j-i+1);
                sum-=nums[i];
                i++;
            }
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};