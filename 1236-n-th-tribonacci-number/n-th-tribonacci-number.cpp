class Solution {
public:
    int tribonacci(int n) {
        if (n == 0 || n == 1)
            return n;
        if (n == 2)
            return 1;
        vector<int> T(n + 1, 0);
        T[0] = 0, T[1] = 1, T[2] = 1;
        int t1 = 0, t2 = 1, t3 = 1;
        for (int i = 3; i <= n; i++) {
            T[i] = T[i - 1] + T[i - 2] + T[i - 3];
        }
        return T[n];
    }
};