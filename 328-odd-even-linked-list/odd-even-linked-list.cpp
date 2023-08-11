class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        vector<int> odd;
        vector<int> even;

        int curr=1;
        ListNode * temp=head;
        while(temp!=nullptr){
            if(curr++ % 2 != 0){
                odd.push_back(temp->val);
            }else{
                even.push_back(temp->val);
            }
            temp=temp->next;
        }

        for(auto i:even){
            odd.push_back(i);
        }

        ListNode * dummy=new ListNode(0);
        ListNode * P=dummy;

        for(auto i:odd){
            ListNode * newNode=new ListNode(i);
            P->next=newNode;
            P=P->next;
        }

        return dummy->next;
    }
};