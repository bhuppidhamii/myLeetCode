class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_set<string> st;
        st.insert("");
        string ans = "";
        for (auto& w : words) {
            string prefix = w.substr(0, w.length() - 1);
            if (st.count(prefix)) { // check if prefix present in set
                st.insert(w);

                if (w.length() > ans.length()) {
                    ans = w;
                } else if (w.length() == ans.length()) {
                    ans = min(ans, w);
                }
            }
        }
        return ans;
    }
};