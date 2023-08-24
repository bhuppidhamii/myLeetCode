class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int r, int c) {
        // min-heap
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                int dist= abs(i-r) + abs(j-c);
                pq.push({dist,{i,j}});
            }
        }
        vector<vector<int>>ans;
        while(pq.empty() == false){
            vector<int>temp = {pq.top().second.first,pq.top().second.second};
            pq.pop();
            ans.push_back(temp);
        }
        return ans;
    }
};