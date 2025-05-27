class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int N = arr.size();
        stack<int> st;
        st.push(arr[N - 1]);
        vector<int> ans(N, 0);
        ans[N - 1] = -1;
        for (int i = N - 2; i >= 0; i--) {
            ans[i] = st.top();
            if (arr[i] > st.top()) {
                st.push(arr[i]);
            }
        }
        return ans;
    }
};