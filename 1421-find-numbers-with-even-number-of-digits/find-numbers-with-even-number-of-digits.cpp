class Solution {
public:
    int calcDigits(int n) {
        int count = 0;
        while (n > 0) {
            count++;
            n /= 10;
        }
        return count;
    }
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (auto& n : nums) {
            int sz = calcDigits(n);
            if (sz % 2 == 0) {
                count++;
            }
        }
        return count;
    }
};