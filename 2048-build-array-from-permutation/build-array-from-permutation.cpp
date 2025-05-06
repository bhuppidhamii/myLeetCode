class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int N=nums.size();
        vector<int>ans(N,0);

        for(int i=0; i<N; i++){
            ans[i]=nums[nums[i]];
        }
        return ans;
    }
};