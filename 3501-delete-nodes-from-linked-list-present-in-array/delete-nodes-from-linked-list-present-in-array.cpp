class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Jai Shri Ram
        unordered_set<int>st(begin(nums), end(nums));
        
        ListNode *dummy = new ListNode(0);
        ListNode *d = dummy;

        ListNode *prev = NULL;
        ListNode *temp = head;

        while(temp){
            if(st.find(temp->val) == st.end()){ // not present in set
                d->next = temp;
                d = d->next;
            }
            prev = temp;
            temp = temp->next;
            prev->next = NULL;
        }
        return dummy->next;
    }
};