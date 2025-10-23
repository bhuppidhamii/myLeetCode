class Solution {
  public:
    #define P pair<int,vector<int>>
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Jai Shri Ram
        
        priority_queue<P>pq; //max-heap
        
        for(auto &p:points){
            int x=p[0];
            int y=p[1];
            int dist = x*x + y*y;
            
            pq.push({dist, p});
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        vector<vector<int>>ans;
        while(pq.size()>0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};