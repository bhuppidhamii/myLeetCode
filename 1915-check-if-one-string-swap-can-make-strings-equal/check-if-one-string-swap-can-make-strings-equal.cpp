class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2)
            return true;

        int n = s1.size();
        string cpy1 = s1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(s1[i], s1[j]);
                if (s1 == s2) {
                    return true;
                } else {
                    s1 = cpy1;
                }
            }
        }

        string cpy2 = s2;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(s2[i], s2[j]);
                if (s2 == s1) {
                    return true;
                } else {
                    s2 = cpy2;
                }
            }
        }
        return false;
    }
};