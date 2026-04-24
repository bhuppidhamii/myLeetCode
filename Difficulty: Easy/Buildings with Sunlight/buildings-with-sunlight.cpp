class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        // Jai Shri Ram
        int count = 0;
        int curr = INT_MIN;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] >= curr){
                count++;
                curr = max(curr, arr[i]);
            }
        }
        return count;
    }
};