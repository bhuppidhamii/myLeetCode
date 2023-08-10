class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int N=nums.size();
        set<int>s;
        for(auto i:nums){
            s.insert(i);
        }
        vector<int>ans;
        for(auto i:s){
            ans.push_back(i);
        }

        int k=3;
        int n=ans.size();
        if(n < k) k=1;
        sort(ans.begin(), ans.end(),[&](auto a,auto b){
            return a<b;
        });
        return ans[n-k];
    }
};