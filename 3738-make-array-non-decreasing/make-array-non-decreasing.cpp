class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int count = 0;
        int prev = -1;

        for (auto& n : nums) {
            if (prev <= n) {
                prev = n;
                count++;
            }
        }
        return count;
    }
};