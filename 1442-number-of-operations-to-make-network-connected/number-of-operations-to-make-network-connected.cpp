class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int i) {
        if (i == parent[i]) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }
    void Unionn(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) {
            return;
        }

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[y_parent] > rank[x_parent]) {
            parent[x_parent] = y_parent;
        } else { // equal rank
            parent[y_parent] = x_parent;
            rank[x_parent]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        if (edges < n - 1)
            return -1;

        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        int components = n; // ilaka
        for (auto& e : connections) {
            int a = e[0];
            int b = e[1];

            // if a'parent != b'parent
            if (find(a) != find(b)) {
                Unionn(a, b);
                components--;
                // ilaka--
            }
        }
        return components - 1;
    }
};