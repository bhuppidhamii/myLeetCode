/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    void insertAtTail(Node* &head, Node* &tail, int data){
        Node* newNode=new Node(data);

        if(head==NULL){
            head=newNode;
            tail=newNode;
            return;
        }else{
            tail->next=newNode;
            tail=tail->next;
        }
    }
public:
    Node* copyRandomList(Node* head) {
        // step1. create a clone list
        Node* cloneHead=NULL;
        Node* cloneTail=NULL;

        Node* originalNode=head;
        while(originalNode!=NULL){
            insertAtTail(cloneHead,cloneTail,originalNode->val);
            originalNode=originalNode->next;
        }
        // step2. create map of original & clone list
        unordered_map<Node*, Node*>m;
        originalNode=head;
        Node* cloneNode=cloneHead;
        while(originalNode && cloneNode){
            m.insert({originalNode, cloneNode});
            originalNode=originalNode->next;
            cloneNode=cloneNode->next;
        }
        // step3. arrange random pointers
        originalNode=head;
        cloneNode=cloneHead;
        while(originalNode!=NULL){
            cloneNode->random=m[originalNode->random];
            originalNode=originalNode->next;
            cloneNode=cloneNode->next;
        }
        return cloneHead;
    }
};