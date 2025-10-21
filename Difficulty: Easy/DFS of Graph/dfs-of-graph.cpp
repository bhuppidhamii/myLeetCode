class Solution {
  public:
    void solve(int u, vector<vector<int>>&adj, vector<bool>&visited, vector<int>&result){
        if(visited[u] == true) return;
        
        result.push_back(u);
        visited[u] = true;
        
        for(auto &v:adj[u]){
            if(visited[v] == false){
                solve(v, adj, visited, result);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Jai Shri Ram
        
        int V = adj.size();
        vector<int>result;
        int source = 0;
        
        vector<bool>visited(V, false);

        // dfs call
        solve(source, adj, visited, result);
        
        return result;
    }
};