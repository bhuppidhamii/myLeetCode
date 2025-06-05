class Solution {
  public:
    int solve(int src, int dest, map<int, vector<int>>&adj, vector<vector<int>>&dp){
        if(src == dest){
            return 1;
        }
        
        if(dp[src][dest] != -1){
            return dp[src][dest];
        }
        
        int count = 0;
        for(auto &v:adj[src]){
            count += solve(v, dest, adj, dp);
        }
        
        return dp[src][dest] = count;
    }
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        // Code here
        map<int, vector<int>>adj;
        for(auto &e:edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }
        vector<vector<int>>dp(V+1, vector<int>(V+1, -1));
        return solve(src, dest, adj, dp);
    }
};