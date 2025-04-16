class Solution {
public:
    int numSub(string s) {
        int N = s.size();
        int i = 0, j = 0, total = 0;
        int M = 1e9 + 7;
        while (i < N) {
            char ch = s[i];
            if (ch == '1') {
                int count = 1;
                j = i + 1;

                while (j < N && s[j] == '1') {
                    count++;
                    j++;
                }
                cout << count<<" - ";
                i = j;
                int curr = (1LL * count * (count + 1)/2) % M;
                total += curr % M;

            } else {
                i++;
            }
        }
        return total;
    }
};