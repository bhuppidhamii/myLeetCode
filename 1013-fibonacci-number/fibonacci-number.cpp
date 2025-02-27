class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1)
            return n;

        int first = 0, second = 1, ans = 0;
        for (int i = 2; i <= n; i++) {
            ans = first + second;
            first = second;
            second = ans;
        }
        return ans;
    }
};