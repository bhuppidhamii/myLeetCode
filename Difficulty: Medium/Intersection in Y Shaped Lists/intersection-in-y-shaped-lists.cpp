/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        // Jai Shri Ram
        int n1=0;
        Node *temp1=head1;
        while(temp1){
            n1++;
            temp1=temp1->next;
        }
        
        int n2=0;
        Node *temp2=head2;
        while(temp2){
            n2++;
            temp2=temp2->next;
        }
        
        int diff = abs(n2-n1);
        
        if(n1>n2){
            // move head head1
            while(diff && head1){
                head1=head1->next;
                diff--;
            }
            
        }else{
            // mode head2
            while(diff && head2){
                head2=head2->next;
                diff--;
            }
        }
        
        while(head1 && head2 && (head1!=head2)){ // compare head pointers
            head1=head1->next;
            head2=head2->next;
            
        }
        return head1;
    }
};