class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int N = arr.size();

        vector<int> left(N, -1);
        stack<int> st;
        for (int i = 0; i < N; i++) {
            while (st.size() > 0 && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (st.size() > 0) {
                left[i] = st.top();
            }
            st.push(i);
        }
        while (!st.empty()) {
            st.pop();
        }

        vector<int> right(N, N);
        for (int i = N - 1; i >= 0; i--) {
            while (st.size() > 0 && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (st.size() > 0) {
                right[i] = st.top();
            }
            st.push(i);
        }

        int M = 1e9 + 7;
        long long sum = 0;
        for (int i = 0; i < N; i++) {
            int lft = (i - left[i]);
            int rgt = (right[i] - i);
            long long ways = (lft * rgt) % M;
            long long total = (arr[i] * ways) % M;
            sum = (sum + total) % M;
        }
        return sum;
    }
};