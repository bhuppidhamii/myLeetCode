/* Node is defined as
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
    Node* segregate(Node* head) {
        if(head==NULL) return head;
        
        Node *zero = new Node(0);
        Node *zeroHead = zero;

        Node *one = new Node(0);
        Node *oneHead = one;

        Node *two = new Node(0);
        Node *twoHead = two;

        Node* temp = head;  // for traversal
        while (temp!=NULL) {
            if (temp->data == 0) {
                zero->next = temp;
                zero = zero->next;
            } else if (temp->data == 1) {
                one->next = temp;
                one = one->next;
            } else { // 2
                two->next = temp;
                two = two->next;
            }
            temp = temp->next;
        }
        
        // Join lists in order 0 -> 1 -> 2
        zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
        one->next = twoHead->next;
        two->next = NULL;   // IMPORTANT: break old links
        
        Node* newHead = NULL;

        if (zeroHead->next) {
            newHead = zeroHead->next;   // start of 0-list
        } else if (oneHead->next) {
            newHead = oneHead->next;    // start of 1-list
        } else {
            newHead = twoHead->next;    // start of 2-list
        }
        
        return newHead;
    }
};