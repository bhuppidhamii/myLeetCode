class Solution {
public:
    int differenceOfSums(int n, int m) {
        // count of numbers divisible by m in rang [1, n];
        int k = n / m;

        // sum of first n natural numbers
        int sum = n * (n + 1) / 2;

        // sum of all nos that are divisible by m in range [1, n]
        int nums2 = m * (k * (k + 1) / 2);

        // sum of all nos that are not divisible by m in range [1, n]
        int nums1 = sum - nums2;

        return nums1 - nums2;
    }
};