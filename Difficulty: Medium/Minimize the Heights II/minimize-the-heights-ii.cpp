class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // Jai Shri Ram
        sort(begin(arr), end(arr));
        
        int n = arr.size();
        int ans = arr[n-1] - arr[0]; // initial answer
        
        // Raise the short towers, lower the tall towers, 
        // and check all possible splits.
        // That’s how we shrink the tallest–shortest gap. ✅
       
        for(int i=1; i < n; i++){
            
            int largest = max(arr[n-1] - k, arr[i-1] + k);
            int smallest = min(arr[0] + k, arr[i] - k);
            
            if(smallest < 0) continue;
            
            int res = largest - smallest;
            ans = min(ans, res);
        }
        return ans;
    }
};