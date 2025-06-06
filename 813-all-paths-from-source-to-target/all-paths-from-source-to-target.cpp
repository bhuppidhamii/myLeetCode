class Solution {
public:
    void solve(int src, int dest, map<int, vector<int>> &adj, vector<int> &temp,vector<vector<int>> &ans){
        temp.push_back(src);

        if(src == dest){
            ans.push_back(temp);
            return;
        }

        for(auto &v:adj[src]){
            solve(v, dest, adj, temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        map<int, vector<int>> adj;
        for (int u = 0; u < n; u++) {
            for (auto& v : graph[u]) {
                adj[u].push_back(v);
            }
        }
        vector<vector<int>> ans;
        vector<int> temp;
        int src = 0;
        int dest = n-1;

        solve(src, dest, adj, temp, ans);
        return ans;
    }
};