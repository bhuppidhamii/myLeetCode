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
        // Jai Shri Ram
        int zeros = 0;
        int ones = 0;
        int twos = 0;
        
        Node *temp = head;
        while(temp){
            if(temp->data == 0){
                zeros++;
            }else if(temp->data == 1){
                ones++;
            }else{
                twos++;
            }
            temp=temp->next;
        }
        
        temp = head;
        while(zeros--){
            temp->data = 0;
            temp=temp->next;
        }
        
        while(ones--){
            temp->data = 1;
            temp=temp->next;
        }
        
        while(twos--){
            temp->data = 2;
            temp=temp->next;
        }
        return head;
    }
};