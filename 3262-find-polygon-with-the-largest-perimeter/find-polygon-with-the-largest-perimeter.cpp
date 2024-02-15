class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(begin(nums), end(nums));

        long long currSum = 0, perimeter = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < currSum) {
                perimeter = currSum + nums[i];
            }

            currSum += nums[i];
        }
        return perimeter == 0 ? -1 : perimeter;
    }
};