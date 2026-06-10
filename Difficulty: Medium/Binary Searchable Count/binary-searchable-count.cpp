class Solution {
  public:
    bool binarySearch(vector<int>&arr, int target){
        int l=0, r=arr.size()-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(arr[mid] == target)return true;
            if(arr[mid] > target){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return false;
    }
    int binarySearchable(vector<int>& arr) {
        // Jai Shri Ram
        int count = 0;
        for(auto &a:arr){
            int target = a;
            if(binarySearch(arr, target)){
                count ++;
            }
        }
        return count;
    }
};