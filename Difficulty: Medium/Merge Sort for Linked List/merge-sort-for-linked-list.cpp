class Solution {
  public:
    Node* merge(Node *l, Node *r){
        Node *dummy = new Node(0);
        Node *temp = dummy;
        
        while(l && r){
            if(l->data <= r->data){
                temp->next = l;
                l = l->next;
            }else{
                temp->next = r;
                r = r->next;
            }
            temp = temp->next;
        }
        
        if(l) temp->next = l;
        
        if(r) temp->next = r;
        
        return dummy->next;
    }
    Node* mergeSort(Node* head) {
        // Jai Shri Ram
        
        if(head->next == NULL) return head;
        
        // find mid
        Node* slow = head;
        Node* fast = head;
        Node* prev = nullptr;
        
        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Cut into two halves
        prev->next = NULL;
        
        Node* l = head;
        Node* r = slow;
        
        l = mergeSort(l);
        r = mergeSort(r);
        
        // merge
        Node* ans = merge(l, r);
        return ans;
    }
};