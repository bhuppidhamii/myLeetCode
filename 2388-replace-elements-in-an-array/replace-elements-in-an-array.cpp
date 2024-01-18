class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]] = i;
        }

        int n=operations.size();
        for(int i=0;i<n;i++){
            int idx=m[operations[i][0]];
            nums[idx]=operations[i][1];

            m[operations[i][1]]=idx;
        }
        return nums;
    }
};