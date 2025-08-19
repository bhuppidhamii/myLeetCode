class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        // Jai Shri Ram
        int N = arr.size();
        
        // create a suffix array which contains the smallest
        // element we've seen so far
        vector<int>suffix(N, 0);
        suffix[N-1] = arr[N-1];
        for(int i=N-2; i>=0; i--){
            suffix[i] = min(suffix[i+1], arr[i]);
        }
        
        // use Binary Search to find the farthest element 
        // that is smaller that arr[i]
        vector<int>res(N, -1);
        for(int i=0; i<N; i++){
            
            // Binary Search-----------
            int low = i+1; // next element of current element
            int high = N-1;
            int ans = -1;
            while(low <= high){
                int mid = low + (high-low)/2;
                
                if(suffix[mid] < arr[i]){
                    ans = mid;
                    // we know ans could be our answer
                    // but we want to find even smaller
                    // so we to to right
                    low = mid + 1;
                }else{
                    high = mid -1;
                }
            }
            
            res[i]=ans;
        }
        
        // res[N-1] will be always -1
        res[N-1] = -1;
        return res;
    }
};