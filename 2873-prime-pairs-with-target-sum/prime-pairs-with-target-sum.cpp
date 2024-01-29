class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        if (n <= 3) {
            return {};
        }

        // Sieve of Eratosthenes

        vector<bool> arr(n + 1, true);  // all numbers are prime
        arr[0] = false, arr[1] = false; // 0 & 1 are not prime

        for (int i = 2; i <= n; i++) {

            if (arr[i] == true && (long)i * i <= n) {

                for (int j = 2 * i; j <= n; j += i) {
                    arr[j] = false;
                }
            }
        }

        vector<int> primeNos;
        for (int i = 2; i <= n; i++) {
            if (arr[i] == true) {
                primeNos.push_back(i);
            }
        }

        vector<vector<int>> ans;
        int sz = primeNos.size();
        int i = 0;
        int j = sz - 1;

        while (i <= j) {
            int currSum = primeNos[i] + primeNos[j];
            if (currSum == n) {
                ans.push_back({primeNos[i], primeNos[j]});
            }
            if (currSum > n) {
                j--;
            } else {
                i++;
            }
        }
        return ans;
    }
};