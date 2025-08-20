class Solution {
  public:
    
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // Jai Shri Ram
        
        // BF-->
        
        // create 1D array from 2D array
        vector<int>v;
        for(auto &arr:mat){
            for(auto &i:arr){
                v.push_back(i);
            }
        }
        
        // sort the 1D array
        sort(v.begin(), v.end());
        
        // perform Binary Search
        int low = 0;
        int high = v.size()-1;
        
        while(low <= high){
            int mid = low+(high-low)/2;
            
            if(v[mid] == x){
                return true;
            }else if(x  > v[mid]){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return false;
    }
};
