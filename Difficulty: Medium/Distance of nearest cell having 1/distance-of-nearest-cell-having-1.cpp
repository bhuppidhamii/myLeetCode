class Solution {
  public:
    int n, m;
    #define P pair<pair<int,int>,int>
    vector<vector<int>> dirs = {{0,1},{0,-1},{-1,0},{1,0}};
    bool isSafe(int i, int j){
        return (i>=0 && i<n && j>=0 && j<m);
    }
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Jai Shri Ram
        n=grid.size(), m=grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false)); // visited array
        
        queue<P>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){ // push all 1 with their distance 0
                    q.push({{i,j}, 0});
                    grid[i][j] = 0; // put 0
                    visited[i][j] = true; // mark as visited
                }
            }
        }
        
        while(q.size() > 0){
            P top = q.front();
            q.pop();
            int r = top.first.first;
            int c = top.first.second;
            int dist = top.second;
            
            for(auto &d:dirs){
                int nr = r + d[0];
                int nc = c + d[1];
                
                if(isSafe(nr, nc) && !visited[nr][nc] && grid[nr][nc]!=1){
                    grid[nr][nc] = dist + 1; // update the distance, i.e parent+1
                    q.push({{nr,nc}, dist + 1});
                    visited[nr][nc] = true;
                }
            }
        }
        return grid;
    }
};