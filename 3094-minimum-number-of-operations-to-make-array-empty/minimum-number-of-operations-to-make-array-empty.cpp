class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int>m;
        for(auto i:nums){
            m[i]++;
        }
        int ans=0;
        for(auto i:m){
            if(i.second==1){
                return -1;
            }
            int freq=i.second;
            ans+=ceil((double)freq/3);
        }
        return ans;
    }
};