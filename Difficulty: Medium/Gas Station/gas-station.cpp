class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        // Jai Shri Ram
        
        // Greedy
        int totalKamai = accumulate(begin(gas), end(gas), 0);
        int totalKharcha = accumulate(begin(cost), end(cost), 0);
        
        if(totalKharcha > totalKamai) return -1;
        
        int n = gas.size();
        
        int result = 0, total = 0;
        for(int i=0; i<n; i++){
            total += gas[i];
            total -= cost[i];
            
            if(total < 0){
                total = 0;
                result = i+1;
            }
        }
        return result;
    }
};