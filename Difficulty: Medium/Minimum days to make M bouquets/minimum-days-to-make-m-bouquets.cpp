class Solution {
  public:
    bool check(vector<int>& arr, int k, int m, int days){
        int count = 0;
        int possibleBq = 0;
        int N = arr.size();
        
        for(int i=0; i<N; i++){
            if(arr[i] <= days){
                count++;
            }else{
                count=0;
            }
            
            if(count == k){
                possibleBq++;
                count=0;
            }
        }
        return possibleBq >= m;
    }
    int minDaysBloom(vector<int>& arr, int k, int m) {
        // Jai Shri Ram
        int low = 0;
        int high = *max_element(begin(arr), end(arr));
        int ans = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            
            if(check(arr, k, m, mid) == true){
                ans = mid;
                high = mid -1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};