class Solution {
  public:
    bool check(vector<int>&arr, int mid, int k){
        int N=arr.size();
        int sum = 0;
        for(auto &i:arr){
            int curr=ceil((double)i/mid);
            sum+=curr;
        }
        return sum<=k;
    }
    int smallestDivisor(vector<int>& arr, int k) {
        // Jai Shri Ram
        sort(begin(arr), end(arr));
        
        int N=arr.size();
        int low=1;
        int high=arr[N-1];
        int ans;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(check(arr, mid, k)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};
