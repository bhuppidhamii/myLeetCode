class Solution {
  public:
    #define P pair<Node*, int>
    int verticalWidth(Node* root) {
        // Jai Shri Ram
        
        if(root == NULL) return 0;
        queue<P>q;
        
        q.push({root, 0});
        int low = 0;
        int high = 0;
        
        while(q.size() > 0){
            int sz = q.size();
            
            for(int i=0; i<sz; i++){
                Node *node = q.front().first;
                int line = q.front().second;
                q.pop();
                
                low = min(low, line);
                high = max(high, line);
                
                if(node->left){
                    q.push({node->left, line-1});
                }
                if(node->right){
                    q.push({node->right, line+1});
                }
            }
        }
        return high-low+1;
    }
};