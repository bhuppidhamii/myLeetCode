class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        int prefixSum = 0;

        unordered_map<int, ListNode*> m;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        m[0] = dummy;

        while (head != NULL) {
            prefixSum += head->val;
            if (m.find(prefixSum) != m.end()) {
                // delete wla kaam -----
                ListNode* start = m[prefixSum];
                ListNode* temp = start;
                int currPSum = prefixSum;
                while (temp != head) {
                    temp = temp->next;
                    currPSum += temp->val;

                    if (temp != head) {
                        m.erase(currPSum);
                    }
                }
                start->next = head->next;
            } else {
                m[prefixSum] = head;
            }

            head = head->next;
        }
        return dummy->next;
    }
};