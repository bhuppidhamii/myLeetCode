class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, int> m1;
        for (auto ch : s) 
            m1[ch]++;
        
        map<char, int> m2;
        for (auto ch : t)
            m2[ch]++;

        if (m1.size() != m2.size())
            return false;

        map<char, char> m3;
        for (int i = 0; i < s.length(); i++) {
            if (m3.find(s[i]) == m3.end()) {
                m3.insert({s[i], t[i]});
            } else {
                if (m3[s[i]] != t[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};