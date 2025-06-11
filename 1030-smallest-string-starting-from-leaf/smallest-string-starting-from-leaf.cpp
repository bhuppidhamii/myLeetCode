class Solution {
public:
    void solve(TreeNode *root, string path, vector<string>&paths){
        if(root == nullptr) return;
        char ch = ('a'+root->val);
        path+=ch;

        if(root->left==nullptr && root->right==nullptr){
            reverse(begin(path), end(path));
            paths.push_back(path);
        }else{
            solve(root->left, path, paths);
            solve(root->right, path, paths);
        }
    }
    string smallestFromLeaf(TreeNode* root) {
        vector<string>paths;
        solve(root, "", paths);
        sort(begin(paths), end(paths));
        for(auto &i:paths){
            cout<<i<<" ";
        }
        return paths[0];
    }
};