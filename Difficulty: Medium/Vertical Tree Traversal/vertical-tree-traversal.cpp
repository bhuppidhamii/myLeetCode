/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    #define P pair<Node*, int>
    vector<vector<int>> verticalOrder(Node *root) {
        // Jai Shri Ram
        map<int,vector<int>>mp;
        queue<P>q;
        
        q.push({root,0});
        
        while(!q.empty()){
            int sz=q.size();
            
            for(int i=0;i<sz;i++){
                Node *node = q.front().first;
                int line = q.front().second;
                q.pop();
                
                mp[line].push_back(node->data);
                
                if(node->left){
                    q.push({node->left, line-1});
                }
                if(node->right){
                    q.push({node->right, line+1});
                }
            }
        }
        vector<vector<int>>result;
        for(auto &i:mp){
            result.push_back(i.second);
        }
        return result;
    }
};