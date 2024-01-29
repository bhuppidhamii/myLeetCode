class Solution {
public:
    int countPrimes(int n) {
        vector<bool> arr(n + 1, true); // set all number to true ie prime
        arr[0] = false;
        arr[1] = false;

        for (int i = 2; i <= n; i++) {
            if (arr[i] == true && (long)i * i <= n) {

                // 2 is prime so set all multiples of 2 as false
                for (int j = 2 * i; j <= n; j += i) {
                    arr[j] = false;
                }
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (arr[i] == true) {
                count++;
            }
        }
        return count;
    }
};