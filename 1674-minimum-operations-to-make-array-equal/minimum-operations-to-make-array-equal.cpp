class Solution {
public:
    int minOperations(int n) {
        vector<int> arr(n, 0);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            arr[i] = (2 * i) + 1;
            sum += arr[i];
        }
        int target = sum / n;
        int ops = 0;
        for (int i = 0; i < n / 2; i++) {
            ops += (target - arr[i]);
        }
        return ops;
    }
};