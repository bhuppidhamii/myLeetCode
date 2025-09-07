/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* merge2list(Node *l1, Node *l2){
        Node *t1 = l1;
        Node *t2 = l2;
        
        Node *dummy = new Node(0);
        Node *ans = dummy;
        while(t1 || t2){
            
            while(t1 && t2){ // if both are ok 
                
                if(t1->data <= t2->data){
                    ans->next = t1;
                    t1 = t1 ->next;
                }else if(t2->data < t1->data){
                    ans->next = t2;
                    t2 = t2->next;
                }
                
                ans = ans->next;
            }
            
            if(t1){
                ans->next = t1;
                t1 = t1->next;
            }
            
            if(t2){
                ans->next = t2;
                t2 = t2->next;
            }
            
            ans = ans->next;
        }
        
        return dummy->next;
    }
    Node* mergeKLists(vector<Node*>& arr) {
        // Jai Shri Ram
        
        Node * l1 = NULL;
        for(auto &head:arr){
            Node *l2 = head;
            
            l1 = merge2list(l1, l2);
        }
        return l1;
    }
};