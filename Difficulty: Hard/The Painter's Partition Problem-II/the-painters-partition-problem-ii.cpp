class Solution {
  public:
    bool check(vector<int>& arr, int k, int time){
        int painter = 1;
        int sum = 0;
        for(int i=0; i<arr.size(); i++){
            if(sum + arr[i] <= time){
                sum+=arr[i];
            }else{
                painter++;
                sum = arr[i];
            }
        }
        return painter<=k;
    }
    int minTime(vector<int>& arr, int k) {
        // Jai Shri Ram
        int low = *max_element(begin(arr), end(arr));
        int high = accumulate(begin(arr), end(arr), 0);
        int ans = 0;
        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(check(arr, k, mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
    }
};