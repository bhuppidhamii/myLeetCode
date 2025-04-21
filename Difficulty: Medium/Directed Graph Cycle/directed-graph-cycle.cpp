//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // Directed Graph - Cycle Detection - BFS
        map<int, vector<int>>adj;
        
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            
            adj[u].push_back(v);
        }
        
        // inDegree 
        vector<int>indegree(V,0);
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            
            indegree[v]++;
        }
        
        
        int nodeCount=0;
        // fill queue with inDegree 0
        queue<int>q;
        for(int i=0; i<V; i++){
            if(indegree[i]==0){
                q.push(i);
                nodeCount++;
            }
        }
        
        // simple bfs
        while(!q.empty()){
            int u=q.front();
            q.pop();
            
            for(auto &v : adj[u]){
                indegree[v]--;
                
                if(indegree[v] == 0){
                    q.push(v);
                    nodeCount++;
                }
            }
        }
        
        // if count == V, then all nodes are visited & topological sort present -> no-cycle
        // topologcial sort is always present in DAG
        // DAG -> Directed Acyclic Graph
        
        if(nodeCount == V){
            return false;
        }
        return true;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends