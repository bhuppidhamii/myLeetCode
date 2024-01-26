class Solution {
public:
    int mod = 1e9 + 7;
    int t[51][51][51];
    int solve(int m, int n, int i, int j, int maxMove) {
        if (i >= m || i < 0 || j >= n || j < 0) {
            // out of boundary;
            return 1;
        }

        if (maxMove <= 0) {
            return 0;
        }

        if (t[i][j][maxMove] != -1) {
            return t[i][j][maxMove];
        }

        long res = 0;

        long up = solve(m, n, i - 1, j, maxMove - 1);
        res += up;
        long down = solve(m, n, i + 1, j, maxMove - 1);
        res += down;
        long left = solve(m, n, i, j - 1, maxMove - 1);
        res += left;
        long right = solve(m, n, i, j + 1, maxMove - 1);
        res += right;

        return t[i][j][maxMove] = res % mod;
    }
    int findPaths(int m, int n, int maxMove, int i, int j) {
        memset(t, -1, sizeof(t));
        return solve(m, n, i, j, maxMove) % mod;
    }
};