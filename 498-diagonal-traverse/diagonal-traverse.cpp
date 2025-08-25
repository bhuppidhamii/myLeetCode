class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>ans;
        map<int, vector<int>>mp;
        int M = mat.size();
        int N = mat[0].size();

        for(int i=0; i<M; i++){
            for(int j=0; j<N; j++){
                int sum = i+j;
                mp[sum].push_back(mat[i][j]);
            }
        }

        int idx = 0;
        for(auto &i:mp){
            vector<int>arr = i.second;
            if(idx%2==0){
                reverse(arr.begin(), arr.end());
            }
            idx++;
            for(auto &a:arr){
                ans.push_back(a);
            }
        }
        return ans;
    }
};