class Solution {
public:
    bool isOdd(int n) { return n % 2; }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i = 0, j = 0, n = nums.size();
        int prevCount = 0;
        int oddCount = 0, res = 0;
        while (j < n) {
            if (isOdd(nums[j])) {
                prevCount = 0;
                oddCount++;
            }

            while (oddCount == k) {
                prevCount++;
                if (i < n && isOdd(nums[i])) {
                    oddCount--;
                }
                i++;
            }
            res += prevCount;
            j++;
        }
        return res;
    }
};