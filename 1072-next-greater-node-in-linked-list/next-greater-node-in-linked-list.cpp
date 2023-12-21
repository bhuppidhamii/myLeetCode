class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* temp = head;
        vector<int> v;
        while (temp != nullptr) {
            v.push_back(temp->val);
            temp = temp->next;
        }

        int N = v.size();
        vector<int> ans(N, 0);
        stack<int> st;
        for (int i = N - 1; i >= 0; i--) {
            if (st.empty()) {

            } else {
                while (!st.empty() && st.top() <= v[i]) {
                    st.pop();
                }

                if (!st.empty() && st.top() > v[i]) {
                    ans[i] = st.top();
                }
            }
            st.push(v[i]);
        }
        return ans;
    }
};