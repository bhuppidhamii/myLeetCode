class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(numCourses, 0);

        // adjacency list
        for (auto& vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];
            // b ----> a
            adj[b].push_back(a);
            // inDegree array
            inDegree[a]++;
        }

        // fill queue with degree 0
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // bfs
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

        // if ans.size() == numCourses it mean it's a valid Topological sort and
        // we can complete all the course
        if (ans.size() == numCourses) {
            return true;
        }
        return false;
    }
};