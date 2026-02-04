class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // Jai Shri Ram
        int maxTime = INT_MIN;
        for(auto &r:right){
            int time = n-r;
            maxTime = max(maxTime, time);
        }
        for(auto &l:left){
            int time = l;
            maxTime = max(maxTime, time);
        }
        return maxTime;
    }
};