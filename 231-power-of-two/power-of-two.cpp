class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !(n & (n - 1));
        // n > 0
        // if a no is power of 2, then n&(n-1)==0
    }
};