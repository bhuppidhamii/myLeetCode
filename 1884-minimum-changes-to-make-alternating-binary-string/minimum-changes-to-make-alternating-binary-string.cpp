class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int count1 = 0, count2 = 0;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                // every even idx -> 0
                if (s[i] != '0') count1++;
            } else {
                // every odd idx -> 1
                if (s[i] != '1') count1++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                // every even idx -> 1
                if (s[i] != '1') count2++;
            } else {
                // every odd idx -> 0
                if (s[i] != '0') count2++;
            }
        }

        return min(count1, count2);
    }
};