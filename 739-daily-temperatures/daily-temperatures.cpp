class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> ans(n, 0);

        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && temp[i] >= temp[st.top()]) {
                st.pop();
            }
            if (!st.empty() && temp[i] < temp[st.top()]) {
                ans[i] = st.top() - i;
            }
            if (st.empty()) {
                ans[i] = 0;
            }
            st.push(i);
        }
        return ans;
    }
};