class Solution {
  public:
    Node* reverseLL(Node *root){
        Node *prev=NULL;
        Node *curr=root;
        Node *forward=root;
        
        while(forward){
            forward = curr->next;
            curr->next = prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    Node* trimZeros(Node *root){
        while(root && root->data == 0){
            root=root->next;
        }
        return root;
    }
    Node* addTwoLists(Node* head1, Node* head2) {
        // Jai Shri Ram
        Node *a = trimZeros(head1);
        a = reverseLL(a);
        
        Node *b = trimZeros(head2);
        b = reverseLL(b);

        Node* temp1 = a;
        Node* temp2 = b;
        
        Node *dummy = new Node(1);
        Node *d = dummy;
        
        int carry = 0;
        while(temp1 || temp2 || carry){
            int num1 = 0;
            if(temp1){
                num1 = temp1->data;
                temp1 = temp1->next;
            }
            int num2 = 0;
            if(temp2){
                num2 = temp2->data;
                temp2 = temp2->next;
            }
            
            int sum = num1+num2+carry;
            
            int rem = sum % 10;
            Node *newNode = new Node(rem);
            
            d->next = newNode;
            d = d->next;
                
            carry = sum / 10;
        }
        
        Node *ans = reverseLL(dummy->next);
        if(ans == NULL) return new Node(0);
        
        return ans;
    }
};