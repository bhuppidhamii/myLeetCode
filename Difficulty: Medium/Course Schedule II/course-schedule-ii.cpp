class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        // Initialize graph and in-degree array
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);
    
        // Build the graph
        for (auto& pre : prerequisites) {
            int dest = pre[0];
            int src = pre[1];
            adj[src].push_back(dest);
            inDegree[dest]++;
        }
    
        // Initialize the queue with 
        // courses having in-degree 0
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
    
        vector<int> order;
    
        // Process nodes with BFS
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            order.push_back(current);
    
            // Reduce in-degree for neighbors
            for (int neighbor : adj[current]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
    
        // Check if the topological sort 
        // is possible (i.e., no cycle)
        if (order.size() == n) {
            return order;
        } 
        
        return {}; 
    
    }
};