class Solution {
  public:
    int minCost(vector<int>& arr) {
        // Jai Shri Ram
        
        // min heap
        priority_queue<int, vector<int>, greater<int>>pq;
        for(auto &i:arr){
            pq.push(i);
        }
        
        if(pq.size() == 1) return 0;
        
        int totalCost = 0;
        while(pq.size() > 1){
            int n1 = pq.top();
            pq.pop();
            
            int n2 = pq.top();
            pq.pop();
            
            int cost = n1+n2;
            totalCost += cost;
            pq.push(cost);
        }
        
        return totalCost;
    }
};