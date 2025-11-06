class Solution {
  public:
    bool dfs(int u, map<int,vector<int>>& adj, vector<bool>&visited, int parent){
        visited[u] = true;
        
        for(auto &v:adj[u]){
            if(v == parent) continue;
            if(visited[v] == true) return true;
            if(dfs(v, adj, visited, u) == true){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Jai Shri Ram
        vector<bool>visited(V, false);
        map<int,vector<int>>adj;
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i=0; i<V; i++){
            if(visited[i] != true){
                if(dfs(i, adj, visited, -1) == true){
                    return true;
                };
            }
        }
        return false;
    }
};