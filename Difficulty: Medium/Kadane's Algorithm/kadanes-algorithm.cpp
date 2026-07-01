class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Jai Shri Ram
        int maxSum = INT_MIN;
        int currSum = 0;
        
        for(int i=0; i<arr.size(); i++){
            currSum += arr[i];
            maxSum = max(currSum, maxSum);
            if(currSum < 0){
                currSum = 0;
            }
        }
        return maxSum;
    }
};