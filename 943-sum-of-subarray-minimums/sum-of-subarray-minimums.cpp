class Solution {
public:
    vector<int> getNSL(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                ans[i] = -1;
            } else {
                while (!st.empty() && arr[st.top()] >= arr[i]) {
                    st.pop();
                }
                ans[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> getNSR(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) {
                ans[i] = n;
            } else {
                while (!st.empty() && arr[st.top()] > arr[i]) {
                    st.pop();
                }
                ans[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> nsl = getNSL(arr);
        vector<int> nsr = getNSR(arr);

        long long sum = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            long long l = i - nsl[i]; 
            // left m kitne smaller elements hain
            long long r = nsr[i] -i ;
            // right m kitne smaller elements hain

            long long total = l * r;
            long long totalSum = arr[i] * total;
            sum = (sum + totalSum) % mod;
        }
        return sum;
    }
};