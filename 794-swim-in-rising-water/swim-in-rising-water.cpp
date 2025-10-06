class Solution {
public:
    vector<vector<int>>directions = {{1,0}, {0, 1}, {-1, 0}, {0, -1}};
    bool check(int i, int j, vector<vector<int>>& grid, int t, vector<vector<bool>>&visited, int n){
        if(i<0||i>=n||j<0||j>=n||grid[i][j]>t||visited[i][j]) return false;

        visited[i][j] = true;

        if(i==n-1 && j==n-1) return true;

        for(auto &d:directions){
            int i_=i+d[0];
            int j_=j+d[1];

            if(check(i_, j_, grid, t, visited, n)){
                return true;
            }
        }

        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        // Jai Shri Ram
        int n = grid.size(); 

        int low = 0, high = n*n-1;
        int ans = 0;
        while(low <= high){
            int mid = low + (high-low)/2;

            vector<vector<bool>>visited(n,vector<bool>(n, false));
            if(check(0, 0, grid, mid, visited, n) == true){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};