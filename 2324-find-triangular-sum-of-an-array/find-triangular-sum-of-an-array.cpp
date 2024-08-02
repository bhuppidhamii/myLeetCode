class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        ans.push_back(nums);
        for (int i = n - 1; i > 0; i--) {
            vector<int> arr(i, 0);
            ans.push_back(arr);
        }
        for(int i=1;i<n;i++){
          int m=ans[i].size();
          for(int j=0;j<m;j++){
            int sum=ans[i-1][j]+ans[i-1][j+1];
            if(sum<10){
            ans[i][j]=sum;
            }else{
              ans[i][j]=sum%10;
            }
          }
        }
        return ans[n-1][0];
    }
};