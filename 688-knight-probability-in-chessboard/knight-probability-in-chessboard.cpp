class Solution {
public:
    double t[101][101][101];

    double solve(int n, int k, int i, int j) {
        if (i >= n || i < 0 || j >= n || j < 0) {
            return 0.0; // out of bound
        }
        if (k == 0) { // path explored
            return 1.0;
        }
        if (t[k][i][j] != -1.0) {
            return t[k][i][j];
        }

        double res = 0.0;
        // for each k move, the knight has 8 moves
        res += solve(n, k - 1, i - 2, j - 1) / 8.0;
        res += solve(n, k - 1, i - 2, j + 1) / 8.0;
        res += solve(n, k - 1, i - 1, j - 2) / 8.0;
        res += solve(n, k - 1, i + 1, j - 2) / 8.0;
        res += solve(n, k - 1, i + 2, j - 1) / 8.0;
        res += solve(n, k - 1, i + 2, j + 1) / 8.0;
        res += solve(n, k - 1, i + 1, j + 2) / 8.0;
        res += solve(n, k - 1, i - 1, j + 2) / 8.0;

        t[k][i][j] = res;
        return res;
    }

    double knightProbability(int n, int k, int i, int j) {
        // memset function is designed to set the bytes in the specified block of memory to a particular value (in this case, -1.0), but it works with bytes, not with double values. Using memset for a double array may lead to unexpected behavior.
        // Initialize the memoization table with -1.0
        for (int x = 0; x < 101; ++x) {
            for (int y = 0; y < 101; ++y) {
                for (int z = 0; z < 101; ++z) {
                    t[x][y][z] = -1.0;
                }
            }
        }

        if (k == 0) {
            return 1.0;
        }
        return solve(n, k, i, j);
    }
};
