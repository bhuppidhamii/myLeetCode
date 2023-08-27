class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        
        // Iterate through all possible subarrays
        for (int i = 0; i < n; i++) {
            int gcd = 0;
            for (int j = i; j < n; j++) {
                // Update gcd for each new element
                gcd = (gcd == 0) ? nums[j] : __gcd(gcd, nums[j]);
                if (gcd == k) {
                    count++;
                }
            }
        }
        
        return count;
    }
};
