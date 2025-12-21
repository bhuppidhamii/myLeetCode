class Solution {
  public:
    int findLowerBound(int target, vector<int>& arr, int low, int high){
        int idx = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(target == arr[mid]){
                idx = mid;
                high = mid-1;
                continue;
            }
            
            if(target > arr[mid]){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return idx;
    }
    int findUpperBound(int target, vector<int>& arr, int low, int high){
        int idx = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            
            if(target == arr[mid]){
                idx = mid;
                low = mid+1;
                continue;
            }
            
            if(target > arr[mid]){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return idx;
    }
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // Jai Shri Ram
        
        vector<int>ans;
        for(auto &q:queries){
            int low = q[0];
            int high = q[1];
            int target = q[2];
            
            // find lower-bound of target in arr
            int lower = findLowerBound(target, arr, low, high);
            // cout<<lower;
            
            // find upper-bound of target in arr
            int upper = findUpperBound(target, arr, low, high);
            // cout<<upper<<" "<<"\n";
            
            // subtract upperbound - lowerbound + 1
            if(lower == -1 && upper == -1){
                ans.push_back(0);
            }else{
                ans.push_back(upper-lower+1);
            }
        }
        return ans;
    }
};