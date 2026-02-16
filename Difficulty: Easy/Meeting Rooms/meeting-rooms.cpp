class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Jai Shri Ram
        sort(begin(arr), end(arr));
        int i=0, n=arr.size();
        while(i<n){
            int start = arr[i][0];
            int end = arr[i][1];
            int j=i+1;
            if(j<n && arr[j][0] < end){
                return false;
            }
            i++;
        }
        return true;
    }
};