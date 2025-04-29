class Solution {
public:
    bool dfs(int u, unordered_map<int, vector<int>>& adj, vector<int>& color, int currColor) {
        color[u] = currColor;
        for (auto& v : adj[u]) {
            if (color[v] ==
                color[u]) { // check present node color equal to next node
                return false;
            }

            if (color[v] == -1) { // if v node is not colored, color it.
                int colorV = 1 - color[u];
                if (dfs(v, adj, color, colorV) == false) {
                    return false;
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

        // color vector ----
        vector<int> color(n, -1);
        // 1 --> Red
        // 0 --> Green

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (dfs(i, adj, color, 1) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};