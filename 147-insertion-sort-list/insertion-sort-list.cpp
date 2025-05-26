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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* temp=head;
        vector<int>v;
        while(temp){
            v.push_back(temp->val);
            temp=temp->next;
        }
        sort(begin(v), end(v));

        ListNode *dummy=new ListNode(-1);
        temp=dummy;
        for(int i=0; i<v.size(); i++){
            ListNode* newNode=new ListNode(v[i]);
            temp->next=newNode;
            temp=temp->next;
        }
        return dummy->next;
    }
};