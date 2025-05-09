class Solution {
public:
    long long dfs(int u, map<int, vector<int>>& adj, vector<bool>&visited, long long &size){
        visited[u] = true;

        for(auto &v : adj[u]){
            if(!visited[v]){
                size+=1;
                dfs(v, adj, visited, size);
            }
        }
        return size;
    } 
    long long countPairs( int n, vector<vector<int>>& edges) {
        // visited array
        vector<bool> visited(n, false);

        // adjacency list
        map<int, vector<int>> adj;
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        long long count=0;
        long long remainingNodes=n;

        // dfs
        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {
                long long size=1;
                dfs(i, adj, visited, size);
                
                count+=(size*(remainingNodes-size));
                remainingNodes-=size;
            }
        }

        return count;
    }
};