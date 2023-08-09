class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        vector<int> vc;
        ListNode* temp=head;
        while(temp!=nullptr){
            vc.push_back(temp->val);
            temp=temp->next;
        }
        int N=vc.size();
        vector<int> ans(N);
        for(int i=0;i<N;i++){
            ans[(i+k)%N]=vc[i];
        }

        ListNode *dummy=new ListNode(0);
        ListNode *P=dummy;
        for(int i=0;i<N;i++){
            ListNode* newNode = new ListNode(ans[i]);
            P->next=newNode;
            P=P->next;
        }

        return dummy->next;
    }
};