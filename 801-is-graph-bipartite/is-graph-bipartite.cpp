class Solution {
public:
    bool bfs(int u, unordered_map<int, vector<int>>& adj, vector<int>& color, int currColor) {
        queue<int> q;
        q.push(u);
        color[u] = currColor;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto& v : adj[u]) {
                if (color[v] == color[u]) { // if adjacent is of same color
                    return false;
                } else if (color[v] == -1) { // not colored or visited
                    color[v] = 1 - color[u];
                    q.push(v);
                }
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        // adjacency list -----
        unordered_map<int, vector<int>> adj;
        for (int u = 0; u < n; u++) {
            for (auto& v : graph[u]) {
                adj[u].push_back(v);
            }
        }

        // color vector -------
        vector<int> color(n, -1);
        // 1 --> Red, 0 --> Green

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (bfs(i, adj, color, 1) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};