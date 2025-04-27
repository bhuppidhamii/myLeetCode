class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> adj;
        int V = numCourses;
        vector<int> inDegree(V, 0);
        for (auto& p : prerequisites) {
            int a = p[0];
            int b = p[1];
            // b--->a
            adj[b].push_back(a);
            inDegree[a]++;
        }

        // topological sort - bfs
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto& v : adj[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
            ans.push_back(u);
        }

        if (ans.size() == V) {
            return ans;
        }
        return {};
    }
};