class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int mini=nums[0];
        int maxi=nums[n-1];

        int ans=__gcd(mini,maxi);
        return ans;
    }
};