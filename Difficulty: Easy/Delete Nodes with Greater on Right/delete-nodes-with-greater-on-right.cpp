/* Structure of a Linked List node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node * reverseList(Node *head){
        Node * curr = head;
        Node * prev = NULL;
        Node * forward = NULL;
        
        while(curr){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    Node *compute(Node *head) {
        // Jai Shri Ram
        
        // reverse the linked list
        head = reverseList(head);
        
        int  currMax = INT_MIN;
        Node * temp = head;
        
        Node * newHead = new Node(0);
        Node * dummy = newHead;
        while(temp){
            if(temp->data >= currMax){
                dummy->next = temp;
                dummy = dummy->next;
            }else{
                dummy->next = NULL;
            }
            currMax = max(currMax, temp->data);
            temp=temp->next;
        }
        //reverse again
        return reverseList(newHead->next);
    }
};