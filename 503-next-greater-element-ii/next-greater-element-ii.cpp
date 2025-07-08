class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int N = nums.size();
        vector<int> ans(N, -1);
        stack<int> st;

        for (int i = 0; i < N; i++) {
            while (!st.empty() && nums[i] > nums[st.top()]) {
                ans[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }

        for (int i = 0; i < N; i++) {
            while (!st.empty() && nums[i] > nums[st.top()]) {
                ans[st.top()] = nums[i];
                st.pop();
            }
        }
        return ans;
    }
};