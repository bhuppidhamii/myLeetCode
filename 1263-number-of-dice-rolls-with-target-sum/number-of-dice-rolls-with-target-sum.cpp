class Solution {
public:
    int M = 1e9 + 7;
    vector<vector<long long>> t;
    int solve(int n, int k, int target) {
        if (target < 0) {
            return 0;
        }
        if (n == 0) {
            if (target == 0) {
                return 1;
            } else {
                return 0;
            }
        }
        if (t[n][target] != -1) {
            return t[n][target];
        }
        long long ways = 0;
        for (int face = 1; face <= k; face++) {
            t[n][target] = ways += solve(n - 1, k, target - face) % M;
        }
        return t[n][target] = ways % M;
    }
    int numRollsToTarget(int n, int k, int target) {
        t.assign(n + 1, vector<long long>(target + 1, -1));
        return solve(n, k, target);
    }
};