class Solution {
public:
    bool goodNumber(int n) {
        bool changed = false;
        while (n > 0) {
            int d = n % 10;
            if (d == 3 || d == 4 || d == 7)
                return false;
            if (d == 2 || d == 5 || d == 6 || d == 9)
                changed = true;
            n = n / 10;
        }
        return changed;
    }
    int rotatedDigits(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (goodNumber(i) == true) {
                count++;
            }
        }
        return count;
    }
};