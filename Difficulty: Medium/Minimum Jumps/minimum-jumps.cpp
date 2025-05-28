class Solution {
  public:
    int N;
    int solve(vector<int>&arr, int i, vector<int>&dp){
        if(i >= N-1) return 0;
        if(arr[i] == 0) return INT_MAX;
        if(dp[i] != -1) return dp[i];
        
        int maxJumps=arr[i];
        int minJumps=INT_MAX;
        for(int j=1; j<=maxJumps&&i+j<N; j++){
            int temp=solve(arr, i+j, dp);
            if(temp != INT_MAX){
                minJumps=min(minJumps, temp+1);
            }
        }
        return dp[i]=minJumps;
    }
    int minJumps(vector<int>& arr) {
        // code here
        N=arr.size();
        vector<int>dp(N+1, -1);
        int ans= solve(arr, 0, dp);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};
