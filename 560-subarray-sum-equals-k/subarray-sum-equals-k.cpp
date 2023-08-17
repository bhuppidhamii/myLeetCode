class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>m;
        int count=0,sum=0;
        m[0]=1;
        for(auto i:nums){
            sum+=i;
            // if(sum == k) count++;
            int rem=sum-k;
            if(m.find(rem) != m.end()){
                count+=m[rem];
            }
            m[sum]++;
        }
        return count;
    }
};