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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy1=new ListNode(0);
        ListNode* less=dummy1;

        ListNode* dummy2=new ListNode(0);
        ListNode* start=dummy2;
        ListNode* great=dummy2;

        ListNode* temp=head;
        while(temp){
            if(temp->val < x){
                ListNode* newNode=new ListNode(temp->val);
                less->next=newNode;
                less=less->next;
            }else{
                ListNode* newNode=new ListNode(temp->val);
                great->next=newNode;
                great=great->next;
            }
            temp=temp->next;
        }

        less->next=start->next;
        return dummy1->next;
    }
};