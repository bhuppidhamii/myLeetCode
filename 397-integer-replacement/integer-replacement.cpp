class Solution {
public:
    double solve(long long int n) {
        if (n <= 1) {
            return 0;
        }
        if (n % 2 == 0) {
            return 1 + solve(n / 2);
        } else {
            long long int add = 1 + solve(n + 1);
            long long int sub = 1 + solve(n - 1);
            return min(add, sub);
        }
    }
    int integerReplacement(int n) { return solve(n); }
};