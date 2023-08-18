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
private:
    ListNode* reverseList(ListNode *root){
        ListNode* prev=NULL;
        ListNode* curr=root;
        ListNode* forw=root;

        while(curr!=nullptr){
            forw=forw->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root1 = reverseList(l1);
        ListNode* root2 = reverseList(l2);

        int carry=0;
        ListNode* dummy=new ListNode();
        ListNode* temp=dummy;
        while(root1 || root2 || carry){
            int sum=carry;

            if(root1){
                sum+=root1->val;
                root1=root1->next;
            }

            if(root2){
                sum+=root2->val;
                root2=root2->next;
            }
            
            ListNode* newNode=new ListNode(sum%10);
            temp->next=newNode;
            temp=temp->next;
            carry=sum/10;
        }
        ListNode *final = dummy->next;
        ListNode *res = reverseList(final);
        return res;
    }
};