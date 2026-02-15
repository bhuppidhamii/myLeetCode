class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // Jai Shri Ram
        // BF
        sort(begin(a), end(a));
        int n = a.size();
        int minDiff = INT_MAX;
        for(int i=0; i<=n-m; i++){
            int mini = a[i];
            int maxi = a[i+m-1];
            minDiff = min(minDiff, maxi-mini);
        }
        return minDiff;
    }
};