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
        
        // BF
        vector<int>v;
        Node *temp = head;
        while(temp){
            v.push_back(temp->data);
            temp=temp->next;
        }
        
        int N = v.size();
        if(k > N) return head; // if not possible
        
        swap(v[k-1], v[N-k]);  // swap
        
        Node * dummy = new Node(0); // create a new node
        temp = dummy;
        
        for(auto &i:v){
            Node *newNode = new Node(i);
            temp->next=newNode;
            temp=temp->next;
        }
        
        return dummy->next;
        
    }
};