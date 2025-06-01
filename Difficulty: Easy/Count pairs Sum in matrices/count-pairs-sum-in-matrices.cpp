class Solution {
  public:
    bool binarySearch(int target, vector<int>&v2){
        int low=0;
        int high=v2.size()-1;
        while(low <= high){
            int mid=low+(high-low)/2;
            if(v2[mid] == target){
                return true;
            }else if( target > v2[mid]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return false;
    }
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
        vector<int>v2;
        for(auto &m:mat2){
            for(auto &i:m){
                v2.push_back(i);
            }
        }
        int count=0;
        for(auto &m:mat1){
            for(auto &i:m){
                int target=x-i;
                if(binarySearch(target, v2) == true){
                    count++;
                }
                    
            }
        }
        return count;
    }
};