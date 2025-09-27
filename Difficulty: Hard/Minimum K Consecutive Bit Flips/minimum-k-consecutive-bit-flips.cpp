class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        // Jai Shri Ram
        
        int n = arr.size();
        int flipCounFromPastFor_i=0;
        vector<bool>isFlipped(n, false);
        
        int flips = 0;
        for(int i=0; i<n; i++){
            
            if(i>=k && isFlipped[i-k]==true){
                flipCounFromPastFor_i--;
            }
            
            if(flipCounFromPastFor_i%2 == arr[i]){
                if(i+k>n){
                    return -1;
                }
                
                flipCounFromPastFor_i++;
                flips++;
                isFlipped[i]=true;
            }
        }
        return flips;
    }
};