class Solution {
public:
    int minSteps(string s, string t) {
        map<char, int> m1;
        for (auto ch : s) {
            m1[ch]++;
        }

        map<char, int> m2;
        for (auto ch : t) {
            m2[ch]++;
        }

        if (m1 == m2)
            return 0;

        int count = 0;
        for (auto i : m1) {
            char ch = i.first;
            int diff = m1[ch] - m2[ch];
            cout<<diff<<" ";
            // count+=count>0?diff:0;
            if (diff > 0) {
                count += diff;
            }
        }
        return count;
    }
};