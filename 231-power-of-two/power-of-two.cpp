class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 1 || n == 0) return n;
        if (n % 2 != 0)
            return false;
        while (n % 2 == 0) {
            n = n / 2;
        }
        return n == 1;
    }
};