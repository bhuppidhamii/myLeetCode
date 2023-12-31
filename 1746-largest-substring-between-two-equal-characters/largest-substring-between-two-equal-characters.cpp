class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = INT_MIN;
        int N = s.size();
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (s[i] == s[j]) {
                    ans = max(j - i - 1, ans);
                }
            }
        }
        if (ans == INT_MIN)
            return -1;
        return ans;
    }
};