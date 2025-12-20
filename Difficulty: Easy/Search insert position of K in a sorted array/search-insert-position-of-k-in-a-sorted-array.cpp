class Solution {
  public:
    int bs(vector<int>&arr, int target){
        int low=0, high=arr.size()-1;
        int ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[mid] == target){
                return mid;
            }
            
            if(arr[mid] > target){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
    int searchInsertK(vector<int> &arr, int k) {
        // Jai Shri Ram
        int n = arr.size();
        if(k < arr[0]) return 0;
        if(k > arr[n-1]) return n;
        return bs(arr, k);
    }
};