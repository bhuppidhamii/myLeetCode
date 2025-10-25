class Solution {
  public:
    int minOperations(vector<int>& arr) {
        // Jai Shri Ram
        double totalSum = accumulate(begin(arr), end(arr), 0);
        double req = totalSum/2;
        // cout<<totalSum<<" "<<req<<"\n";
        
        priority_queue<double> pq(begin(arr), end(arr)); // max-heap
        int ops = 0;
        while(totalSum > req && pq.size() > 0){
            double top = pq.top();
            pq.pop();
            
            top/=2; // half-it
            
            totalSum-=top; // subtract it from totalSum
            pq.push(top); // push the half one
            // cout<<top<<"\n";
            ops++; // increase operations;
        }
        return ops;
    }
};