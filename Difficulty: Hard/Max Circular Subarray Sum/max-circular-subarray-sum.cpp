class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // Jai Shri Ram
        int N = arr.size();
        
        int minSubSum = INT_MAX;
        int curr = 0;
        for(int i=0; i<N; i++){
            curr = min(arr[i], curr+arr[i]);
            minSubSum = min(curr, minSubSum);
        }
        
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        int maxCircularSum = totalSum - minSubSum;
        
        int maxSubSum = INT_MIN;
        curr = 0;
        for(int i=0; i<N; i++){
            curr = max(arr[i], curr+arr[i]);
            maxSubSum = max(maxSubSum, curr);
        }
        
        if(maxCircularSum == 0){
            return maxSubSum;
        }
        
        return max(maxSubSum, maxCircularSum);
        
    }
};