class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count = 0;

        for (int i = 0; i < nums.size() - 2; i++) {
            int first = nums[i];
            int second = nums[i + 1];
            int third = nums[i + 2];
            if ((first + third)*2 == second) {
                cout<<first+third;
                cout<<"-"<<second/2;
                count++;
            }
        }
        return count;
    }
};