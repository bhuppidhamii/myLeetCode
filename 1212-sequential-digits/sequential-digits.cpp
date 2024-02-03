class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;
        for (int i = 1; i <= 8; i++) {
            q.push(i);
        }
        vector<int> ans;
        while (!q.empty()) {
            int n = q.front();
            q.pop();
            if (n >= low && n <= high) {
                ans.push_back(n);
            }
            int ld = n % 10;
            if (ld + 1 <= 9) {
                q.push(n * 10 + (ld + 1));
            }
        }
        return ans;
    }
};