class Solution {
public:
    int minDist(vector<int>& v, int i) {
        int ans = INT_MAX;
        for (auto& p : v) {
            ans = min(ans, abs(p - i));
        }
        return ans;
    }
    vector<int> shortestToChar(string s, char c) {
        vector<int> v;
        int N = s.size();
        for (int i = 0; i < N; i++) {
            if (s[i] == c) {
                v.push_back(i);
            }
        }
        vector<int> ans;
        for (int i = 0; i < N; i++) {
            ans.push_back(minDist(v, i));
        }
        return ans;
    }
};