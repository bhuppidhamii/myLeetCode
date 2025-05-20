/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void makeGraph(map<int, vector<int>>& adj, TreeNode* root, int parent) {
        if (root == nullptr)
            return;
        if (parent != -1) {
            adj[root->val].push_back(parent);
        }
        if (root->left) {
            adj[root->val].push_back(root->left->val);
        }
        if (root->right) {
            adj[root->val].push_back(root->right->val);
        }
        makeGraph(adj, root->left, root->val);
        makeGraph(adj, root->right, root->val);
    }
    int amountOfTime(TreeNode* root, int start) {
        map<int, vector<int>> adj;
        // make graph
        makeGraph(adj, root, -1);

        // apply bfs from start node
        queue<int> q;
        q.push(start);

        unordered_set<int> visited;
        visited.insert(start);

        int minutes = 0;
        while (!q.empty()) {
            int N = q.size();

            while (N--) {
                int curr = q.front();
                q.pop();

                for (auto& i : adj[curr]) {
                    if (visited.find(i) == visited.end()) {
                        visited.insert(i);
                        q.push(i);
                    }
                }
            }
            minutes++;
        }

        return minutes - 1;
    }
};