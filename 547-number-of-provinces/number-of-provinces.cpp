class Solution {
public:
    void dfs(map<int, vector<int>>& adj, int u, vector<bool>& visited) {
        if (visited[u] == true) {
            return;
        }
        visited[u] = true;

        for (auto& v : adj[u]) {
            if (visited[v] == false) {
                dfs(adj, v, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {

        map<int, vector<int>> adj;
        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected[i].size(); j++) {
                if (isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }
        // cout << adj.size();

        // for (auto& u : adj) {
        //     cout << u.first << " - ";
        //     for (auto& v : u.second) {
        //         cout << v << " ";
        //     }
        //     cout << "\n";
        // }

        int V = isConnected.size(), count = 0;
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(adj, i, visited);
                count++;
            }
        }
        return count;
    }
};