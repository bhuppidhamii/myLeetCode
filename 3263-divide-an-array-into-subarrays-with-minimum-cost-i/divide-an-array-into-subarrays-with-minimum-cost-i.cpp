class Solution {
public:
    int minimumCost(vector<int>& nums) {
        sort(begin(nums)+1,end(nums));
        for(auto i:nums){
            cout<<i<<" ";
        }
        return nums[0]+nums[1]+nums[2];
    }
};