class Solution {
  public:
    bool check(vector<int> &arr, int k, int mid){
        int parts = 0;
        int sum = 0;
        int N = arr.size(), i = 0;
        
        while(i < N){
            
            while(i<N && sum+arr[i] <= mid){
                sum+=arr[i];
                i++;
            }
            parts++;
            sum = 0;
        }
        return parts <= k;
    }
    int findPages(vector<int> &arr, int k) {
        // Jai Shri Ram
        if(k > arr.size()) return -1;
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        
        int ans = -1;
        while(low <= high){
            int mid = low +(high-low)/2;
            
            if(check(arr, k, mid) == true){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
        // return check(arr, k, 113);
    }
};