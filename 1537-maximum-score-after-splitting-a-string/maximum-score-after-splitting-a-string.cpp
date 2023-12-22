class Solution {
private:
    int count1(string str) {
        int cnt = 0;
        for (auto ch : str) {
            if (ch == '1')
                cnt++;
        }
        return cnt;
    }
public:
    int maxScore(string s) {
        int N = s.size();
        int ans = INT_MIN;
        for (int i = 0; i < N - 1; i++) {
            string left = s.substr(0, i + 1);
            string right = s.substr(i + 1, N - (i + 1));
            int sum = (left.size() - count1(left)) + count1(right);
            ans = max(ans, sum);
        }
        return ans;
    }
};