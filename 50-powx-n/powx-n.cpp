class Solution {
public:
    double solve(double x, long long N) {
        if (N == 0)
            return 1;
        double half = solve(x, N / 2);
        double ans = half * half;

        if (N % 2 == 1) {
            ans = x * ans;
        }
        return ans;
    }
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        return solve(x, N);
    }
};