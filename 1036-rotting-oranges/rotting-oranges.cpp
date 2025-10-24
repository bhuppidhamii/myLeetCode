class Solution {
public:
    #define P pair<int,int>
    int m, n;
    vector<vector<int>>dirs={{0,1},{0,-1},{-1,0},{1,0}};
    bool isSafe(int i, int j){
        if(i>=0 && i<m && j>=0 && j<n) return true;
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size(), n=grid[0].size();

        vector<vector<bool>>visited(m, vector<bool>(n, false));

        queue<P>q;
        // multi-source bfs
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                    visited[i][j]=true;
                }
            }
        }

        int time = 0;
        while(q.size() > 0){
            int sz = q.size();
            for(int k=0; k<sz; k++){

                auto[r,c] = q.front();
                q.pop();

                for(auto &d:dirs){
                    int nr = r+d[0];
                    int nc = c+d[1];

                    if(isSafe(nr, nc)==true && grid[nr][nc]!=0 && !visited[nr][nc]){
                        q.push({nr, nc});
                        visited[nr][nc]=true;
                    }
                }
            }
            
            if(q.size() > 0){
                time++;
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1 && visited[i][j]==false) return -1;
            }
        }

        return time;
    }
};