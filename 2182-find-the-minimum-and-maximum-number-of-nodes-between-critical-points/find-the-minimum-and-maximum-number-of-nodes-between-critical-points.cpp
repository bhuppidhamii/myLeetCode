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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==NULL||head->next==NULL || head->next->next==NULL){
            return {-1,-1};
        }
        int pos=2;
        ListNode *curr=head->next;
        ListNode *prev=head;
        ListNode *forw=curr->next;

        vector<int>criticalPoints;
        while(curr!=nullptr && forw!=nullptr){
            if(curr->val > prev->val && curr->val > forw->val){
                // check maxima
                criticalPoints.push_back(pos);
            }else if(curr->val < prev->val && curr->val < forw->val){
                // check minima
                criticalPoints.push_back(pos);
            }
            curr=curr->next;
            prev=prev->next;
            forw=forw->next;
            pos++;

        }
        int n=criticalPoints.size();
        if(n==0){
            return {-1,-1};
        }
        sort(criticalPoints.begin(), criticalPoints.end());
        int mini=INT_MAX;
        int maxi=abs(criticalPoints[0]-criticalPoints[n-1]);
        for(int i=1;i<n;i++){
            int diff=abs(criticalPoints[i]-criticalPoints[i-1]);
            mini=min(diff, mini);
        }
        if(mini==INT_MAX || maxi==INT_MIN){
            return {-1,-1};
        }
        return {mini,maxi};
    }
};