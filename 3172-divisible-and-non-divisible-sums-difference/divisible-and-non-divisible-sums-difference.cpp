class Solution {
public:
    int differenceOfSums(int n, int m) {
        int k = n / m; // count of numbers divisible by m in rang [1,n];

        // sum of first n natural numbers
        int sum = n * (n + 1) / 2;

        int nums2 = 0;
        for (int i = 1; i <= k; i++) {
            nums2 += (m * i);
        }
        cout << nums2 << " - " << sum;
        return sum - 2 * nums2;
    }
};