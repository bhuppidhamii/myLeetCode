class Solution {
public:
    bool hasAlternatingBits(int n) {
        while (n > 0) {
            if ((n & 1) ^ ((n >> 1) & 1) == 0) {
                return false;
            }
            n >>= 1;
        }
        return true;
    }
};