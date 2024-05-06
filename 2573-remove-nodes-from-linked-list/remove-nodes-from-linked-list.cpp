/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        vector<int> arr;
        while (head != nullptr) {
            arr.push_back(head->val);
            head = head->next;
        }
        stack<int> st;
        int n = arr.size();
        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) {
                st.push(arr[i]);
            } else {
                if (st.empty() == false && arr[i] >= st.top()) {
                    st.push(arr[i]);
                }
            }
        }
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while (!st.empty()) {
            ListNode* newNode = new ListNode(st.top());
            temp->next = newNode;
            temp = temp->next;
            st.pop();
        }
        return dummy->next;
    }
};