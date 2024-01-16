class Solution {
public:
    vector<int>v;
    Solution(ListNode* head) {
        while(head!=NULL){
            v.push_back(head->val);
            head=head->next;
        }
    }
    
    int getRandom() {
        int idx=rand()%v.size();
        return v[idx];
    }
};
