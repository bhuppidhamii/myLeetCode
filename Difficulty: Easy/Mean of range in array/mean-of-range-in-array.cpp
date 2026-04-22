class Solution {
  public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        // Jai Shri Ram
        
        vector<int>cumSum;
        int cSum = 0;
        for(int i=0; i<arr.size(); i++){
            cSum+=arr[i];
            cumSum.push_back(cSum);
        }
        
        vector<int>ans;
        for(auto &q: queries){
            int i=q[0],j=q[1];
            int len = (j-i)+1;
            
            int sum = cumSum[j];
            if(i-1 >= 0){
                sum-=cumSum[i-1];
            }
            ans.push_back(sum/len);
        }
        return ans;
    }
};