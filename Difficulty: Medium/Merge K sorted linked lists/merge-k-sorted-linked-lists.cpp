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
    Node* mergeKLists(vector<Node*>& arr) {
        // Jai Shri Ram
        
        // BF------->
        
        // store all values in an array
        vector<int>v;
        for(auto &head:arr){
            Node *temp = head;
            while(temp){
                v.push_back(temp->data);
                temp=temp->next;
            }
        }
        
        // sort the array
        sort(begin(v), end(v));
        
        // dummy technique
        Node *dummy = new Node(0);
        Node *temp = dummy;
        
        // simple traversal & node creation
        for(auto &i:v){
            Node *newNode = new Node(i);
            temp->next = newNode;
            temp = temp->next;
        }
        
        return dummy->next;
    }
};