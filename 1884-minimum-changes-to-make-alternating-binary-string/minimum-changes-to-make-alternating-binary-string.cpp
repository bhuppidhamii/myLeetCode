class Solution {
public:
    int minOperations(string s) {
        int N = s.size(), cnt1 = 0, cnt2 = 0;
        bool curr1 = s[0] - '0';
        bool curr2 = !curr1;
        cout << curr1 << " " << curr2;

        for (int i = 0; i < N; i++) {
            if (s[i] - '0' != curr1) {
                cnt1++;
            }
            curr1 = !curr1;

            if (s[i] - '0' != curr2) {
                cnt2++;
            }
            curr2 = !curr2;
        }
        return min(cnt1, cnt2);
    }
};