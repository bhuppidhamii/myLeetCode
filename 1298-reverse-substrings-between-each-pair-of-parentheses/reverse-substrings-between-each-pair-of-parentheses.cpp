class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string result = "";

        for (auto ch : s) {
            if (ch == '(') {
                st.push(result.size());
            } else if (ch == ')') {
                int skip = st.top();
                st.pop();
                reverse(result.begin() + skip, result.end());
                cout << result << " ";
            } else {
                result += ch;
            }
        }
        return result;
    }
};