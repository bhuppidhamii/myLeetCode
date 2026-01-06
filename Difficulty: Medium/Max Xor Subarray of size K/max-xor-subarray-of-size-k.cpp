class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // Jai Shri Ram
        
        int n = arr.size();
        int curr = 0, maxor = INT_MIN;
        
        for(int i=0; i<k-1; i++){
            curr = curr xor arr[i];
        }
        int i = 0;
        for(int j=k-1; j<n; j++){
            curr = curr xor arr[j];
            maxor = max(maxor, curr);
            
            curr = curr xor arr[i];
            i++;
        }
        return maxor;
    }
};