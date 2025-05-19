//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        map<int,vector<pair<int,int>>>adj;
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        
        vector<int>result(V,INT_MAX);
        result[src]=0;
        pq.push({0, src});
        
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            
            pq.pop();
            for(auto &vec:adj[node]){
                int adjNode=vec.first;
                int wt=vec.second;
                
                if(d+wt < result[adjNode]){
                    result[adjNode]=d+wt;
                    pq.push({d+wt, adjNode});
                }
            }
        }
        return result;
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            edges.push_back({v, u, w});
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(V, edges, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends