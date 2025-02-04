class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();

        int i=0,maxi=INT_MIN;
        while(i<n){
            int j=i,currSum=nums[j];
            while(j+1<n && nums[j+1]>nums[j]){
                currSum+=nums[j+1];
                j++;
            }
            maxi=max(maxi,currSum);
            i=j+1;
        }
        return maxi;
    }
};