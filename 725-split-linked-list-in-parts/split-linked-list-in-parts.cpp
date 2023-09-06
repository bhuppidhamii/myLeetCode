class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int N = 0;
        ListNode* temp = head;
        while (temp) {
            N++;
            temp = temp->next;
        }
        int size = N / k;
        int rem = N % k;

        vector<ListNode*> ans(k, nullptr);
        int idx = 0;
        temp = head;
        while (temp != nullptr) {
            ListNode* dummy = new ListNode(0);
            ListNode* curr = dummy;
            for (int i = 0; i < size; i++) {
                if (temp) {
                    ListNode* newNode = new ListNode(temp->val);
                    curr->next = newNode;
                    temp = temp->next;
                    curr = curr->next;
                }
            }
            if (rem > 0 && temp) {
                ListNode* newNode = new ListNode(temp->val);
                curr->next = newNode;
                temp = temp->next;
                curr = curr->next;
                rem--;
            }
            ans[idx++] = dummy->next;
        }
        return ans;
    }
};
