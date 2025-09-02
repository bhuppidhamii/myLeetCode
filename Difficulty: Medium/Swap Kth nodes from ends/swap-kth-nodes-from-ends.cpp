/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        // Jai Shri Ram
        
        // little optimal
        int N = 0;
        Node *temp = head;
        while(temp){
            N++;
            temp=temp->next;
        }
        
        if(k>N) return head;
        
        // find the pos of kth node
        int i = 1;
        temp=head;
        while(i<k){
            temp=temp->next;
            i++;
        }
        Node * a = temp;
        
        // find pos of N-kth node
        i=0;
        temp=head;
        while(i < N-k){
            temp=temp->next;
            i++;
        }
        Node *b = temp;
        
        // swap
        int c=a->data;
        a->data=b->data;
        b->data=c;
        
        return head;
    }
};