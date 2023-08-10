class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int N=nums.size();
        map<int,int>m;
        for(auto i:nums){
            m[i]++;
        }
        for(auto i:nums){
            if(m[i] > N/2){
                return i;
            }
        }
        return -1;
    }
};