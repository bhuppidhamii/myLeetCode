class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // Jai Shri Ram
        Node *slow = head;
        Node *fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                break;
            }
        }
        
        // no cycle
        if(fast==nullptr || fast->next == NULL) return 0; 
        
        // cout<<slow->data<<" ";
        Node *temp = slow->next;
        // cout<<temp->data<<"\n";
        int count = 1;
        while(temp != slow){
            count++;
            temp=temp->next;
        }
        
        return count;
    }
};