class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // Jai Shri Ram
        
        sort(begin(arr), end(arr));
        
        int n=arr.size();
        int ans = arr[n-1]-arr[0];
        
        for(int i=1; i<n; i++){
            int largest = max(arr[n-1] - k, arr[i-1] + k);
            
            int smallest = min(arr[0] + k, arr[i] - k);
            // if(smallest < 0) continue; -- heights can be nagative
            
            ans = min(ans, largest-smallest);
        }
        return ans;
    }
};