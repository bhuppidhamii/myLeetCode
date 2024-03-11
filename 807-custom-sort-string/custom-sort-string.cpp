class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> m;
        for (char i : s)
            m[i]++;

        string ans = "";
        for (char ch : order) {
            if (m.find(ch) != m.end()) {
                ans += string(m[ch], ch);
                m.erase(ch);
            }
        }

        for (auto i : m)
            ans += string(i.second, i.first);

        return ans;
    }
};