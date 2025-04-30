class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (auto& n : nums) {
            if (n >= 10 && n <= 99) {
                count++;
            } else if (n >= 1000 && n <= 9999) {
                count++;
            } else if (n == 100000) {
                count++;
            }
        }
        return count;
    }
};