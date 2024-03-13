class Solution {
public:
    int pivotInteger(int n) {
        for (int i = 1; i <= n; i++) {
            // left sum
            int leftSum = 0;
            for (int j = 1; j <= i; j++) {
                leftSum += j;
            }

            // right sum
            int rightSum = 0;
            for (int j = i; j <= n; j++) {
                rightSum += j;
            }

            if (leftSum == rightSum) {
                return i;
            }
        }
        return -1;
    }
};