class Solution {
public:
    vector<vector<int>>ans;
    vector<int>v;
    bool inOrder(TreeNode* root){   // LNR
        if(root==NULL) return false;

        v.push_back(root->val);
        
        if(inOrder(root->left) || inOrder(root->right)){
            return true;
        }

        if(root->left==NULL && root->right==NULL){
            ans.push_back(v);
        }

        v.pop_back();
        return false;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        TreeNode *temp=root;
        bool b=inOrder(temp);
        vector<string>res;
        for(auto v:ans){
            string s="";
            for(auto i:v){
                s+=to_string(i);
                s+="->";
            }
            s.pop_back();
            s.pop_back();
            res.push_back(s);
        }

        return res;
    }
};