class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;

        for (auto& ch : s) {
            if (ch >= '0' && ch <= '9') {
                st.pop();
            } else {
                st.push(ch);
            }
        }
        string ans = "";
        while (st.size() > 0) {
            char ch = st.top();
            st.pop();

            ans = ch + ans;
        }
        return ans;
    }
};