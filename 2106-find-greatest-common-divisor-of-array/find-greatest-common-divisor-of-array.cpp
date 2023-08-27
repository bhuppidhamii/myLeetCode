class Solution {
private:
    int getGCD(int a, int b){
        int mini=min(a,b);
        int ans;
        for(int i=mini;i>=1;i--){
            if(a%i == 0 && b%i == 0){
                ans=i;
                break;
            }
        }
        return ans;
    }
public:
    int findGCD(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int mini=nums[0];
        int maxi=nums[n-1];

        int ans=getGCD(mini,maxi);
        return ans;
    }
};