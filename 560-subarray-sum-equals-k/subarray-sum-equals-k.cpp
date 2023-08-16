class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int N=nums.size();
        map<int,int>m;
        //prefixSum,count
        int count=0, sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==k) count++;
            int rem=sum-k;
            if( m.find(rem) != m.end() ){
                count+=m[rem];
            }
            m[sum]++;
        }
        return count;
    }
};