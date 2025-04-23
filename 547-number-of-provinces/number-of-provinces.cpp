class Solution {
public:
    void bfs(vector<vector<int>>& isConnected, int u, vector<bool>& visited) {
        queue<int> q;

        q.push(u);
        visited[u] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v = 0; v < isConnected.size(); v++) {
                if (isConnected[u][v] == 1) {
                    if (visited[v] == false) {
                        q.push(v);
                        visited[v] = true;
                    }
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();

        vector<bool> visited(V, false);
        int count = 0;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                bfs(isConnected, i, visited);
                count++;
            }
        }
        return count;
    }
};