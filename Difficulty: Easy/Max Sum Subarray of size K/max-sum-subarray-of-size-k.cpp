class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // Jai Shri Ram
        
        int currSum=0, n=arr.size();
        for(int i=0; i<k-1; i++){
            currSum+=arr[i];
        }
        
        int maxSum = INT_MIN;
        for(int i=k-1; i<n; i++){
            currSum+=arr[i];
            
            maxSum = max(maxSum, currSum);
            currSum-=arr[i-(k-1)];
        }
        return maxSum;
    }
};