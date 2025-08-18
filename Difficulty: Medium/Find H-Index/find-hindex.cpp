class Solution {
  public:
    bool check(vector<int>&arr, int mid){
        int count = 0;
        for(auto &i:arr){
            if(i >= mid){
                count++;
            }
        }
        if(count >= mid) return true;
        return false;
    }
    int hIndex(vector<int>& arr) {
        // Jai Shri Ram
        int low = 1;
        int high = *max_element(arr.begin(), arr.end());
        
        int ans = 0;
        while(low <= high){
            int mid = low +(high-low)/2;
            if(check(arr, mid) == true){
                ans = mid;
                low = mid+1; // inc low -> we need maximum value
            }else{
                high = mid-1;
            }
        }
        return ans;
    }
};