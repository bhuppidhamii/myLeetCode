class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int>st(begin(nums), end(nums));

        // BF
        ListNode *temp = head;
        vector<int>v;
        while(temp){
            if(st.find(temp->val) == st.end()){ // not found in set
                v.push_back(temp->val);
            }
            temp=temp->next;
        }
        
        ListNode *dummy = new ListNode(0);
        temp = dummy;
        for(auto &i:v){
            ListNode *newNode = new ListNode(i);
            temp->next = newNode;
            temp = temp->next;
        }
        return dummy->next;
    }
};