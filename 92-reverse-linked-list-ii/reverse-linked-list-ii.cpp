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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int>arr;
        ListNode*temp=head;
        while(temp){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        reverse(arr.begin()+(left-1), arr.begin()+(right));
        ListNode* dummy=new ListNode(0);
        temp=dummy;
        for(auto i:arr){
            ListNode* newNode=new ListNode(i);
            temp->next=newNode;
            temp=temp->next;
        }
        return dummy->next;
    }
};