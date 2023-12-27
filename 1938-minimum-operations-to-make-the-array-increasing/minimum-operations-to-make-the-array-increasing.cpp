class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            while(nums[i+1]<=nums[i]){
                nums[i+1]+=1;
                cnt++;
            }
        }
        return cnt;
    }
};