class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // Jai Shri Ram
        int N = arr.size();
        int zeroCount  = 0;
        int max_len = 0;
        int i = 0;
        for(int j =0; j<N; j++){
            if(arr[j] == 0) zeroCount++;
            
            while(i < N && zeroCount > k){
                if(arr[i] == 0) zeroCount--;
                i++;
            }
            int len = j-i+1;
            max_len = max(max_len, len);
        }
        return max_len;
    }
};
