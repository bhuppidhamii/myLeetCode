/*
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        // Jai Shri Ram
        vector<int>result;
        
        queue<Node*>q;
        q.push(root);
        int row = 0;
        while(q.size() > 0){
            int sz = q.size();
            
            vector<int>lvl;
            for(int i=0; i<sz; i++){
                Node *node = q.front();
                q.pop();
                
                lvl.push_back(node->data);
                
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            if(row % 2 != 0){
                reverse(begin(lvl), end(lvl));
            }
            // insert all nodes of lvl to result
            for(auto &l:lvl){
                result.push_back(l);
            }
            
            row++;
        }
        return result;
    }
};