class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> m;
        m[0]=1;
        int sum=0, count=0;
        for(auto i:nums){
            sum+=i;
            int rem=sum % k;
            if(rem < 0 ){
                rem+=k;
            }
            if(m.find(rem) != m.end()){
                count+=m[rem];
            }
            m[rem]++;
        }
        return count;
    }
};