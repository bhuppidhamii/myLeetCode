class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (x == parent[x])
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent)
            return;

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        rank.resize(26, 0);
        parent.resize(26);
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }

        for (auto& s : equations) {
            if (s[1] == '=') {
                Union(s[0] - 'a', s[3] - 'a');
            }
        }

        for (auto& s : equations) {
            if (s[1] == '!') {
                char a = s[0];
                char b = s[3];

                int parent_a = find(a - 'a');
                int parent_b = find(b - 'a');

                if (parent_a == parent_b) {
                    return false;
                }
            }
        }
        return true;
    }
};