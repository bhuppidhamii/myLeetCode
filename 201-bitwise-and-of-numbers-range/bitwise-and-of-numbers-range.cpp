class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        // while both nos are not same!
        while (left != right) {
            left = left >> 1;
            right = right >> 1;
            shift++;
        }
        // left pad those shifts
        while (shift--) {
            left = left << 1;
        }
        return left;
    }
};