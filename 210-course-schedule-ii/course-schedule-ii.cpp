class Solution {
public:
    bool dfs(int u, unordered_map<int, vector<int>>& adj, vector<bool>& visited,
             vector<bool>& inRecursion, stack<int>& st) {
        visited[u] = true;
        inRecursion[u] = true;

        for (auto& v : adj[u]) {
            if (!visited[v]) {
                if (dfs(v, adj, visited, inRecursion, st)) {
                    return true;
                }
            } else if (inRecursion[v]) {
                return true; // Found a back edge -> cycle
            }
        }
        inRecursion[u] = false;
        st.push(u);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        int V = numCourses;
        for (auto& p : prerequisites) {
            int a = p[0];
            int b = p[1];
            // b--->a
            adj[b].push_back(a);
        }

        // dfs
        vector<bool> visited(V, false);
        vector<bool> inRecursion(V, false);
        stack<int> st;

        bool isCyclePresent = false;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                isCyclePresent = dfs(i, adj, visited, inRecursion, st);
                if (isCyclePresent == true) {
                    return {};
                }
            }
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};