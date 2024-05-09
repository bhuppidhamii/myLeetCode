class Solution {
public:
    ListNode* reverseLL(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* last = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
    ListNode* doubleIt(ListNode* head) {
        head = reverseLL(head);

        ListNode* curr = head;
        ListNode* prev = NULL;
        int carry = 0;

        while (curr != NULL) {
            int newValue = curr->val * 2 + carry;
            curr->val = newValue % 10;

            if (newValue >= 10) {
                carry = 1;
            } else {
                carry = 0;
            }
            prev = curr;
            curr = curr->next;
        }
        if (carry != 0) {
            ListNode* newNode = new ListNode(carry);
            prev->next = newNode;
        }
        return reverseLL(head);
    }
};