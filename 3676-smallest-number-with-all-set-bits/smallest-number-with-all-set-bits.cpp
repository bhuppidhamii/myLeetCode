class Solution {
public:
    bool allOnes(int n) {
        while (n > 0) {
            int rem = n % 2;
            if (rem == 0)
                return false;
            n /= 2;
        }
        return true;
    }
    int smallestNumber(int n) {
        for (int i = n; i <= 10000; i++) {
            if (allOnes(i) == true) {
                return i;
            }
        }
        return -1;
    }
};