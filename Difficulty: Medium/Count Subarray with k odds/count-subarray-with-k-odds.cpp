class Solution {
  public:
    bool isOdd(int n){
        return n%2==1;
    }
    int atMost(int k, vector<int>& arr){
        int j=0, i=0, n=arr.size();
        int res = 0;
        int oddCount = 0;
        while(j<n){
            if(isOdd(arr[j])) oddCount++;
            
            while(i<n && oddCount > k){
                if(isOdd(arr[i])) oddCount--;
                i++;
            }
            
            int len = j-i+1;
            res+=len;
            j++;
        }
        return res;
    }
    int countSubarrays(vector<int>& arr, int k) {
        // Jai Shri Ram
        return atMost(k, arr)-atMost(k-1, arr);
    }
};