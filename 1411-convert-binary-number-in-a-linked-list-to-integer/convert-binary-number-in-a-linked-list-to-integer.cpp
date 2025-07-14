class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        int n = 0;
        while (temp) {
            n++;
            temp = temp->next;
        }
        temp = head;
        int res = 0;
        for (int i = n - 1; i >= 0; i--) {
            res += (temp->val) * (int)pow(2, i);
            temp = temp->next;
        }
        return res;
    }
};