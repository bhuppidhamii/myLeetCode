class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        sort(envelopes.begin(),envelopes.end(),[&](auto a, auto b){
           if(a[0] == b[0]){
               return a[1] > b[1];
           }else{
               return a[0] < b[0];
           }
        });
        
        vector<int>width;
        for(auto i:envelopes){
            width.push_back(i[1]);
        }

        // Longest Increasing Subsequence
        n=width.size();
        vector<int>ans;
        ans.push_back(width[0]);

        for(int i=1;i<n;i++){
            if(width[i] > ans.back()){
                ans.push_back(width[i]);
            }else{
                int index=lower_bound(ans.begin(), ans.end(), width[i]) - ans.begin();
                ans[index]=width[i];
            }
        }
        return ans.size();
        
    }
};