class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int N=nums.size();
        vector<int>even;
        vector<int>odd;
        for(auto i:nums){
            if(i%2==0){
                even.push_back(i);
            }else{
                odd.push_back(i);
            }
        }

        vector<int>ans(N);
        int e=0;
        int o=0;
        for(int i=0;i<N;i++){
            if(i%2==0){
                ans[i]=even[e++];
            }else{
                ans[i]=odd[o++];
            }
        }
        return ans;
    }
};