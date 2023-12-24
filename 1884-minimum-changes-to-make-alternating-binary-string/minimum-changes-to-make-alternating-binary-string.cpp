class Solution {
public:
    int minOperations(string s) {
        int N = s.size();
        string str1 = "", str2 = "";
        for (int i = 0; i < N; i++) {
            if (i % 2 == 0) {
                str1 += '0';
                str2 += '1';
            } else {
                str1 += '1';
                str2 += '0';
            }
        }

        cout << s << "\n" << str1 << "\n" << str2;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < N; i++) {
            if (s[i] != str1[i]) {
                cnt1++;
            }

            if (s[i] != str2[i]) {
                cnt2++;
            }
        }

        return min(cnt1, cnt2);
    }
};