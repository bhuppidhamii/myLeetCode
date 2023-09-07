class Solution {
private:
    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* forw = head;

        while (curr != nullptr) {
            forw = forw->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* start = prev->next;
        ListNode* end = start;

        for (int i = left; i < right; i++) {
            end = end->next;
        }

        ListNode* lastPart = end->next;
        end->next = nullptr;

        // Update 'prev' before reversing the sublist
        prev->next = nullptr;

        ListNode* reversed = reverseLL(start);
        prev->next = reversed;
        start->next = lastPart;

        return dummy->next;
    }
};
