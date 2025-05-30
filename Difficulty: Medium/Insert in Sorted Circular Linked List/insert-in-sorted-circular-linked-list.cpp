/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        Node* newNode = new Node(data);
        
        Node *last = head;
        while(last->data <= last->next->data){
            last=last->next;
        }
        
        // if data is less than head
        if(head == nullptr || data <= head->data){
            newNode->next=head;
            last->next=newNode;
            return newNode;
        }
        
        
        // if data is greater than last
        if(data >= last->data){
            last->next=newNode;
            newNode->next=head;
            return head;
        }
        
        // if data is present in middle
        // Node *prev=nullptr;
        Node *curr=head;
        while(curr){
            if(data >= curr->data && data <= curr->next->data){
                newNode->next=curr->next;
                curr->next = newNode;
                break;
            }
            curr = curr->next;
        }
        return head;
    }
};