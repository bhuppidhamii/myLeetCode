class Solution {
public:
    TreeNode* createParentMapping(TreeNode* root, int start, map<TreeNode*, TreeNode*>& m) {
        TreeNode* res = NULL;

        queue<TreeNode*> q;
        q.push(root);
        m[root]=NULL;

        while (q.empty() == false) {
            TreeNode* front = q.front();
            q.pop();

            if (front->val == start) {
                res = front;
            }
            
            if(front->left){
                m[front->left]=front;
                q.push(front->left);
            }

            if(front->right){
                m[front->right]=front;
                q.push(front->right);
            }
        }
        return res;
    }

    void infectTree(TreeNode* root,map<TreeNode*, TreeNode*>& m,int &t){
        map<TreeNode*,bool>visited;
        queue<TreeNode*>q;

        q.push(root);
        visited[root]=true;

        while(q.empty()==false){
            int size=q.size();
            bool flag=0;
            for(int i=0;i<size;i++){
                TreeNode* front=q.front();
                q.pop();

                if(front->left!=NULL && visited[front->left]==false){
                    q.push(front->left);
                    visited[front->left]=true;
                    flag=1;
                }
                if(front->right!=NULL && visited[front->right]==false){
                    q.push(front->right);
                    visited[front->right]=true;
                    flag=1;
                }
                if(m[front]!=NULL && visited[m[front]]==false){
                    q.push(m[front]);
                    visited[m[front]]=true;
                    flag=1;
                }
            }
            if(flag==1){
                t++;
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> m;
        int t = 0;
        TreeNode* targetNode = createParentMapping(root, start, m);
        infectTree(targetNode, m, t);
        return t;
    }
};