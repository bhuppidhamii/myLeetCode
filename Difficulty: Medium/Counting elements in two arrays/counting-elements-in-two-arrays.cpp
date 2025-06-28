class Solution {
  public:
    int binarySearch(vector<int>&b, int target){
        int low=0, high=b.size()-1;
        int ans=-1;
        while(low <= high){
            int mid = low+(high-low)/2;
           if(b[mid] <= target){
               low=mid+1;
           }else{
               high=mid-1;
           }
        }
        return low;
    }
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // Jai Shri Ram
        
        // this array we will use for searching and finding how many 
        // elements are smaller than a[i] 
        sort(begin(b), end(b));
        vector<int>ans;
        for(auto &n:a){
            int idx=binarySearch(b, n);
            ans.push_back(idx);
        }
        return ans;
        
    }
};