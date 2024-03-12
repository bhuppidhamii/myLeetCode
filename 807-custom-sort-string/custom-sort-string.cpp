class Solution {
public:
    string customSortString(string order, string s) {
        map<char, int> m; // indexing of char
        for (int i = 0; i < order.length(); i++) {
            m[order[i]] = i;
        }

        auto myComparator = [&m](char& ch1, char& ch2) {
            if (m[ch1] < m[ch2]) {
                return true;
            } else {
                return false;
            }
        };
        sort(begin(s), end(s), myComparator);

        return s;
    }
};