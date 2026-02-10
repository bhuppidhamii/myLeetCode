class Solution {
  public:
    bool check(vector<int>& arr, int k, int s){
        int hrs = 0;
        for(auto &i:arr){
            if(i <= s){
                hrs += 1;
            }else{
                if(i%s == 0){
                    hrs += i/s;
                }else{
                    hrs += i/s;
                    hrs++;
                }
            }
        }
        return (hrs <= k);
    }
    int kokoEat(vector<int>& arr, int k) {
        // Jai Shri Ram
        
        int low = 1;
        int high = *max_element(begin(arr), end(arr));
        // cout<<low<<" "<<high<<"\n";
        int ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(check(arr, k, mid) == true){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};