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
    ListNode* mergeNodes(ListNode* head) {
        vector<int>arr;
        ListNode* temp=head;
        while(temp!=NULL){
          arr.push_back(temp->val);
          temp=temp->next;
        }
        
        int n=arr.size();
        int i=1;
        vector<int>arr1;
        while(i<n){
          int j=i,sum=0;
          while(arr[j]!=0 && j<n){
            sum+=arr[j];
            j++;
          }
          arr1.push_back(sum);
          i=++j;
        }
        ListNode *dummy=new ListNode(0);
        ListNode *tmp=dummy;
        for(auto i:arr1){
          ListNode *newNode=new ListNode(i);
          tmp->next=newNode;
          tmp=tmp->next;
        }
        return dummy->next;
    }
};