class Solution {
public:
    void bfs(map<int, vector<int>>& adj, int u, vector<bool>& visited) {

        queue<int> q;

        q.push(u);
        visited[u] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto& v : adj[u]) {
                if (visited[v] == false) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        map<int, vector<int>> adj;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> visited(V, false);
        int count = 0;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                bfs(adj, i, visited);
                count++;
            }
        }
        return count;
    }
};