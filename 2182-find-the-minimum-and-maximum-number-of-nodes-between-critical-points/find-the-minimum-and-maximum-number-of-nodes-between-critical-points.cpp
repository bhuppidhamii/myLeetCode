
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>arr;
        ListNode *temp=head;
        while(temp!=NULL){
          arr.push_back(temp->val);
          temp=temp->next;
        }
        if(arr.size()<3){
          return {-1,-1};
        }
        vector<int>cpoints;
        for(int i=1;i<arr.size()-1;i++){
          if(arr[i]>arr[i+1]&&arr[i]>arr[i-1]){
            cpoints.push_back(i);
          }else if(arr[i]<arr[i+1]&&arr[i]<arr[i-1]){
            cpoints.push_back(i);
          }
        }
        sort(cpoints.begin(), cpoints.end());
        int n=cpoints.size();
        if(n<2){
          return {-1,-1};
        }
        int maxDist=INT_MIN;
        int minDist=INT_MAX;
        maxDist=cpoints[n-1]-cpoints[0];
        for(int i=1;i<n;i++){
          int diff=cpoints[i]-cpoints[i-1];
          if(diff<minDist){
            minDist=diff;
          }
        }
        return {minDist,maxDist};
    }
};