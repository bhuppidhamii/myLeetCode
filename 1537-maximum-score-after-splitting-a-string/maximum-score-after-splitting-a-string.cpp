class Solution {
public:
    int maxScore(string s) {
        int N = s.size();

        vector<int> prefix0(N, 0);
        int cnt0 = 0;
        for (int i = 0; i < N; i++) {
            if (s[i] == '0') {
                cnt0++;
            }
            prefix0[i] = cnt0;
        }

        vector<int> prefix1(N, 0);
        int cnt1 = 0;
        for (int i = N - 1; i >= 0; i--) {
            if (s[i] == '1') {
                cnt1++;
            }
            prefix1[i] = cnt1;
        }

        int ans = INT_MIN;
        for (int i = 0; i < N - 1; i++) {
            int sum = prefix0[i] + prefix1[i + 1];
            ans = max(sum, ans);
        }
        return ans;
    }
};