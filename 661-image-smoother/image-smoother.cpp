class Solution {
public:
    vector<vector<int>>dim = {
        {-1,-1}, {-1,0}, {-1,1},
        {0,-1}, {0,0}, {0,1},
        {1,-1}, {1,0}, {1,1}
    };
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
       int m=img.size(), n=img[0].size();

        vector<vector<int>>ans(m, vector<int>(n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                int cnt=0, sum=0;
                for(auto &d:dim){
                    int i_= i + d[0];
                    int j_= j + d[1];
                    if(i_>=0 && i_<m && j_>=0 && j_<n){
                        sum+=img[i_][j_];
                        cnt++;
                    }
                }

                ans[i][j] = sum/cnt;
            }
        }
        return ans;
    }
};