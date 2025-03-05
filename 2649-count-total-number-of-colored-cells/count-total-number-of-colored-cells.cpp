class Solution {
public:
    long long coloredCells(int n) {
        long long cells = 1 + (2 * (long long)(n - 1) * n);

        return cells;
    }
};