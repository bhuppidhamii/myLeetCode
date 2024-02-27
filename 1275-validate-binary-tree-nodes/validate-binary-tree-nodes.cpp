class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        map<int, int> m;                    // ChildtoParent
        map<int, vector<int>> adjList; // adjacency list for traversal

        for (int i = 0; i < n; i++) {
            int node = i;
            int left = leftChild[i];
            int right = rightChild[i];

            if (left != -1) {
                adjList[node].push_back(left);

                if (m.find(left) != m.end()) {
                    return false;
                }
                m[left] = node;
            }

            if (right != -1) {
                adjList[node].push_back(right);

                if (m.find(right) != m.end()) {
                    return false;
                }
                m[right] = node;
            }
        }

        int root = -1;
        for (int i = 0; i < n; i++) {
            if (m.find(i) == m.end()) { // parent will be not present in map
                if (root != -1)
                    return false; // 2 roots
                root = i;
            }
        }

        if (root == -1)
            return false; // every i is present in map;

        // bfs
        int count = 0;
        queue<int> q;
        vector<bool> visited(n, false);

        q.push(root);
        count++;
        visited[root] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int& v : adjList[node]) {
                if (visited[v] == false) {
                    visited[v] == true;
                    count++;
                    q.push(v);
                }
            }
        }
        return count == n;
    }
};