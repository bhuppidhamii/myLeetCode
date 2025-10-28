class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();

        vector<int>left(n);
        left[0]=nums[0];
        for(int i=1; i<n; i++){
            left[i]=left[i-1]+nums[i];
        }

        vector<int>right(n);
        right[n-1]=nums[n-1];
        for(int i=n-2; i>=0; i--){
            right[i]=right[i+1]+nums[i];
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){

                int leftSum = 0;
                if(i-1 >= 0) leftSum = left[i-1];

                int rightSum = 0;
                if(i+1 < n) rightSum = right[i+1];

                if(leftSum ==  rightSum){
                    ans+=2;
                }else if(abs(leftSum-rightSum) == 1){
                    ans+=1;
                }
            }
        }
        return ans;
    }
};