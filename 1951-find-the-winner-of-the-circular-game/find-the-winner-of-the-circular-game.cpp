class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            q.push(i);
        }

        while (q.size() > 1) {
            int k1 = k - 1;
            while (k1--) {
                int n = q.front();
                q.pop();
                q.push(n);
            }
            q.pop();
        }
        return q.front();
    }
};