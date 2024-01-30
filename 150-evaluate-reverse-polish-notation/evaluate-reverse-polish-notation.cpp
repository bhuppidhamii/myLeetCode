class Solution {
public:
    int fun(int a, int b, string ch) {
        if (ch == "+") {
            return a + b;
        } else if (ch == "-") {
            return a - b;
        } else if (ch == "*") {
            return a * b;
        }
        return a / b;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (auto t : tokens) {
            if (st.empty()) {
                st.push(stoi(t));
            } else {
                if (t == "+" || t == "-" || t == "/" || t == "*") {
                    int b = st.top();
                    st.pop();
                    int a = st.top();
                    st.pop();

                    st.push(fun(a, b, t));
                } else {
                    st.push(stoi(t));
                }
            }
        }
        return st.top();
    }
};