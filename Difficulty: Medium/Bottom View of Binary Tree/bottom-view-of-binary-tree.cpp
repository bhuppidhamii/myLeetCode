/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    typedef pair<Node*,int> P;
    vector<int> bottomView(Node *root) {
        // Jai Shri Ram
        
        map<int,int>mp; // line, node
        queue<P>q;  // node, line
        
        q.push({root, 0});
        
        while(q.size() > 0){
            int sz = q.size();
            
            for(int i=0; i<sz; i++){
                Node* node = q.front().first;
                int line = q.front().second;
                q.pop();
                
                // update the map
                mp[line] = node->data; 
                
                if(node->left) q.push({node->left, line-1});
                
                if(node->right) q.push({node->right, line+1});
            }
        }
        
        vector<int>ans;
        for(auto &i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};