class Solution {
public:
    // vector<vector<int>>paths;
    bool findPath(TreeNode *root, int target, vector<int>&path){
        if(root==NULL) return false;

        path.push_back(root->val);
        if(root->val==target) return true;

        if(findPath(root->left, target, path) || findPath(root->right, target, path)){
            return true;
        }

        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Jai Shri Ram
        vector<int>path1;
        findPath(root, p->val, path1);

        vector<int>path2;
        findPath(root, q->val, path2);

        map<int,int>mp;
        for(auto &i:path1){
            cout<<i<<" ";
            mp[i]++;
        }
        cout<<"\n";
        for(auto &i:path2){
            cout<<i<<" ";
            mp[i]++;
        }
        cout<<"\n";
        int i = 0;
        while(i < path1.size() && i < path2.size() && path1[i] == path2[i]) {
            i++;
        }

        int lca_val = path1[i-1]; // common ancestor value
        // if both the datas are same, return last node
        TreeNode * newNode = new TreeNode(lca_val);
        return newNode;
    }
};