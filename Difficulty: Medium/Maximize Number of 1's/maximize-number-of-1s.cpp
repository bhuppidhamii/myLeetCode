class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // Jai Shri Ram
        int n=arr.size();
        int maxLen = INT_MIN;
        int i=0;
        for(int j=0; j<n; j++){
            while(arr[j] == 0 && k <= 0){
                if(arr[i] == 0){
                    k++;
                }
                i++;
            }
            if(arr[j] == 0 && k>0){
                k--;
            }
            
            int len = j-i+1;
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};
