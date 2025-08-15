class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n < 1) return false;
        double x = log10(n) / log10(4);

        return x == (int)x;
    }
};