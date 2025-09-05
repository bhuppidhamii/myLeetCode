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
    vector<int> DNF(vector<int>&arr){
        int N = arr.size();
        int i=0, j=0, k=N-1;
        
        while(j<=k){
            if(arr[j]==2){
                swap(arr[j], arr[k]);
                k--;
            }else if(arr[j]==0){
                swap(arr[j], arr[i]);
                i++,j++;
            }else{ // arr[j] == 1
                j++;
            }
        }
        return arr;
    }
    Node* segregate(Node* head) {
        // Jai Shri Ram
        
        // BF
        vector<int>v;
        Node *temp = head;
        while(temp){
            v.push_back(temp->data);
            temp=temp->next;
        }
        
        // sort using DNF algorithm
        vector<int>arr = DNF(v);
        
        // dummy -> technique;
        Node *dummy = new Node(0);
        temp = dummy;
        
        for(auto &i:arr){
            Node *newNode = new Node(i);
            temp->next = newNode;
            temp=temp->next;
        }
        return dummy->next;
    }
};