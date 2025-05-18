class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;

        // Find middle of the linked list
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Break and reverse second half of the list
        ListNode *newList = slow;
        ListNode *prev = nullptr;
        ListNode *curr = newList;
        ListNode *forward;

        while (curr != nullptr) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
 
        newList = prev; // now newList points to the head of reversed second half

        // Compare first and second halves
        int maxi = INT_MIN;
        while (newList != nullptr && head != nullptr) {
            maxi = max(maxi, newList->val + head->val);
            newList = newList->next;
            head = head->next;
        }

        return maxi;
    }
};