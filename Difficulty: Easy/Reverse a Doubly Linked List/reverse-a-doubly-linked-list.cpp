/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // Jai Shri Ram
        Node *temp = NULL;
        Node *curr = head;
        Node *forward = head;
        
        while(curr){
            forward = forward->next;
            curr->next = temp;
            curr->prev = forward;
            temp = curr;
            curr = forward;
        }
        
        head = temp;
        return head;
    }
};