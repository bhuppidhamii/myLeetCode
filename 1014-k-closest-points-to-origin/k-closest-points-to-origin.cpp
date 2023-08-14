class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //max-heap
        priority_queue<pair <int, pair <int,int> >>pq;
        //distance & coordinates
        
        int N=points.size();
        for(int i=0;i<N;i++){

            int x=points[i][0];
            int y=points[i][1];
            int dist=(x*x + y*y);
            
            pq.push({dist,{x,y}});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>>ans;
        while(pq.size()){
            vector<int>temp;
            temp.push_back(pq.top().second.first);
            temp.push_back(pq.top().second.second);
            ans.push_back(temp);
            pq.pop();
        }
        return ans;
    }
};