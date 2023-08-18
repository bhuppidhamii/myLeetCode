class Solution {
public:
    int dominantIndex(vector<int>& nums) {
       int maxi=INT_MIN;
       int idx=-1;
       for(int i=0;i < nums.size();i++){
           if(nums[i] > maxi){
               maxi=nums[i];
               idx=i;
           }
       }

       for(auto i:nums){
           if(i==maxi){
               continue;
           }
           if(( 2*i > maxi)){
               return -1;
           }
       }

       return idx;
    }
};