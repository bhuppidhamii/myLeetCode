class Solution {
public:
    int countHomogenous(string s) {
        int M = 1e9 + 7;
        int N = s.size();
        int total = 0;
        int i = 0, j = 0;
        while (i < N) {
            char ch = s[i];
            int count = 1;
            j = i + 1;
            while (j < N && s[j] == ch) {
                count++;
                j++;
            }
            long long curr =  (1LL * count * (count + 1) / 2) % M;
            total +=curr % M;
            i = j;
        }
        return total;
    }
};