class Solution {
public:
    int M = 1e9 + 7;
    int t[301][301];
    int solve(int n, int i, int x) {
        if (n == 0)
            return 1;
        if (n < 0)
            return 0;

        int currPower = pow(i, x);
        if (currPower > n)
            return 0;

        if (t[n][i] != -1)
            return t[n][i];

        int take = solve(n - currPower, i + 1, x);
        int skip = solve(n, i + 1, x);

        return t[n][i] = (take + skip) % M;
    }

    int numberOfWays(int n, int x) {
        memset(t, -1, sizeof(t));
        return solve(n, 1, x);
    }
};