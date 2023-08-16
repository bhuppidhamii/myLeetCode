class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
       map<int,int>m;
       int sum=0,count=0;
       for(auto i:nums) {
           sum+=i;
           if(sum == k){
               count++;
           }
           int rem=sum-k;
           if(m.find(rem) != m.end()){
               count+=m[rem];
           }
           m[sum]++;
       }
       return count;
    }
};