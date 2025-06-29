class Solution {
  public:
    bool valid(vector<int>&arr, int k, int mid){
        int parts=0;
        int i=0, N=arr.size();
        int curr=0;
        while(i < N){
            int j=i;
            while(j < N && curr+arr[j] <= mid){
                curr+=arr[j];
                j++;
            }
            parts++;
            curr=0;
            i=j;
        }
        return parts <= k;
    }
    int findPages(vector<int> &arr, int k) {
        // Jai Shri Ram
        int N = arr.size();
        if(k > N) return -1;
        
        int low=*max_element(begin(arr), end(arr));
        int high=accumulate(begin(arr), end(arr), 0);
        
        int ans=-1;
        while(low <= high){
            int mid=low+(high-low)/2;
            if(valid(arr, k, mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};