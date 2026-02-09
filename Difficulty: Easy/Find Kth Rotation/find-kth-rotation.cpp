class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Jai Shri Ram
        
        // return the index of smallest element in arr 
        int n = arr.size();
        int ans = -1, smallestEle = INT_MAX;
        for(int i=0; i<n; i++){
            if(arr[i] < smallestEle){
                smallestEle = arr[i];
                ans = i;
            }
        }
        return ans;
    }
};
