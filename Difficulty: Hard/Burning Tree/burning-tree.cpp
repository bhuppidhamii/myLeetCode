/*
class Node {
  public:
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
    void makeGraph(map<int, vector<int>>& adj, Node* root, int parent) {
        if (root == nullptr)
            return;
        if (parent != -1) {
            adj[root->data].push_back(parent);
        }
        if (root->left) {
            adj[root->data].push_back(root->left->data);
        }
        if (root->right) {
            adj[root->data].push_back(root->right->data);
        }
        makeGraph(adj, root->left, root->data);
        makeGraph(adj, root->right, root->data);
    }
    int minTime(Node* root, int start) {
        // code here
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