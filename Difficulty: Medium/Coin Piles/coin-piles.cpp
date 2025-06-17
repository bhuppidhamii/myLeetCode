class Solution {
public:
    int minimumCoins(vector<int>& arr, int k) {
        // Jai Shri Ram
        sort(begin(arr), end(arr));
        int N = arr.size();

        vector<int> prefix(N, 0);
        prefix[0] = arr[0];
        for (int i = 1; i < N; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
        }

        int ans = INT_MAX;
        int prev = 0;

        for (int i = 0; i < N; i++) {
            int max_allowed = arr[i] + k;
            int idx = upper_bound(arr.begin() + i, arr.end(), max_allowed) - arr.begin();

            if (i > 0) {
                prev = prefix[i - 1];
            }

            int suffixSum = (idx > 0) ? prefix[N - 1] - prefix[idx - 1] : prefix[N - 1];
            int totalToRemove = prev + suffixSum - (max_allowed) * (N - idx);

            ans = min(ans, totalToRemove);
        }

        return ans;
    }
};