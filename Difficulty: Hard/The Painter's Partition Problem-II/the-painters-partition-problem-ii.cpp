// User function template for C++

class Solution {
  public:
    bool valid(vector<int>& arr, int k, int mid){
        int N=arr.size(), i=0;
        int parts=0, sum=0;
        
        while(i < N){
            int j=i;
            while(j < N && sum+arr[j] <= mid){
                sum+=arr[j];
                j++;
            }
            i=j;
            parts++;
            sum=0;
        }
        return parts <= k;
    }
    int minTime(vector<int>& arr, int k) {
        // Jai Shri Ram
        int low=*max_element(begin(arr), end(arr));
        int high=accumulate(begin(arr), end(arr), 0);
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(valid(arr, k, mid)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};