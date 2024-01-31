class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2 = nums2.size();
        vector<int> NGR(n2, 0);

        stack<int> st;
        for (int i = n2 - 1; i >= 0; i--) {
            while (!st.empty() && nums2[i] >= nums2[st.top()]) {
                st.pop();
            }
            if (!st.empty() && nums2[i] < nums2[st.top()]) {
                NGR[i] = nums2[st.top()];
            }
            if (st.empty()) {
                NGR[i] = -1;
            }
            st.push(i);
        }

        unordered_map<int, int> m;
        for (int i = 0; i < n2; i++) {
            m[nums2[i]] = NGR[i];
        }

        vector<int> ans;
        for (auto i : nums1) {
            ans.push_back(m[i]);
        }
        return ans;
    }
};