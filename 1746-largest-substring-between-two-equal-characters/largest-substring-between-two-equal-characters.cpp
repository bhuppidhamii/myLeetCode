class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        map<char, int> m;
        int ans = -1, N = s.size();
        for (int i = 0; i < N; i++) {
            if (m.find(s[i]) != m.end()) {
                ans = max(ans, i - m[s[i]] - 1);
            } else {
                m[s[i]] = i;
            }
        }
        return ans;
    }
};