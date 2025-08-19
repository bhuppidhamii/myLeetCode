class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;
        int N = nums.size();

        int i = 0;
        while (i < N) {
            if (nums[i] == 0) {
                count++;
                int j = i + 1;
                while (j < N && nums[j] == 0) {
                    count += (j - i + 1);
                    j++;
                }
                i=j;
            } else {
                i++;
            }
        }
        return count;
    }
};