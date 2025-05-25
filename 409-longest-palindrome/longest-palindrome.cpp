class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> st;
        int result = 0;
        for (auto& ch : s) {
            if (st.find(ch) != st.end()) {
                result += 2;
                st.erase(ch);
            } else {
                st.insert(ch);
            }
        }
        if (st.size() > 0) {
            return result + 1;
        }
        return result;
    }
};