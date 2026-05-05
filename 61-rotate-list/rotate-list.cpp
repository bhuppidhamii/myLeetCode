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
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }
        if (len == 0)
            return nullptr;
        k = k % len;

        ListNode* head_copy = head;
        temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        // make circular linked list
        temp->next = head_copy;
        int rem = len - k - 1;

        temp = head_copy;

        while (rem && temp) {
            temp = temp->next;
            rem--;
        }
        head = temp->next;
        temp->next = nullptr;
        return head;
    }
};