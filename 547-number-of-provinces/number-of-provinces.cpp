class Solution {
public:
    int N;
    void dfs(vector<vector<int>>& isConnected, int u, vector<bool>& visited) {
        visited[u] = true;

        for (int v = 0; v < N; v++) {
            if (visited[v] == false && isConnected[u][v] == 1) {
                dfs(isConnected, v, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        N = isConnected.size();
        int V = isConnected.size(), count = 0;
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(isConnected, i, visited);
                count++;
            }
        }
        return count;
    }
};