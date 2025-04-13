class Solution {
public:
    int M = 1e9 + 7;
    int powSolve(long long a, long long b) {
        if (b == 0)
            return 1;
        long long half = powSolve(a, b / 2);
        long long res = (half * half) % M;
        if (b % 2 == 1) {
            res = (res * a) % M;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        // Binary Exponentiation
        return (long long)powSolve(5, (n + 1) / 2) * powSolve(4, n / 2)%M;
    }
};