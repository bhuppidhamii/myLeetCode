class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> m;
        for (char i : s) {
            m[i]++;
        }

        string ans = "";
        for (char ch : order) {
            if (m.find(ch) != m.end()) {
                for (int i = 0; i < m[ch]; i++) {
                    ans += ch;
                }
                m.erase(ch);
            }
        }
        
        for (auto i : m) {
            for (int j = 0; j < i.second; j++) {
                ans += i.first;
            }
        }
        return ans;
    }
};