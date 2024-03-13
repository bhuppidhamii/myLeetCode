class Solution {
public:
    int pivotInteger(int n) {
        int total = (n * (n + 1)) / 2;
        int currSum = 0;
        for (int i = 1; i <= n; i++) {
            currSum += i;
            if (currSum == ((total - currSum) + i)) {
                return i;
            }
        }
        return -1;
    }
};