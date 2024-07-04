class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* t = dummy;

        ListNode* temp = head;
        temp = temp->next;
        while (temp != NULL) {
            ListNode* temp1 = temp;
            int sum = 0;
            while (temp1->val != 0 && temp1 != NULL) {
                sum += temp1->val;
                temp1 = temp1->next;
            }
            temp = temp1->next;
            ListNode* newNode = new ListNode(sum);
            t->next = newNode;
            t = t->next;
        }
        return dummy->next;
    }
};