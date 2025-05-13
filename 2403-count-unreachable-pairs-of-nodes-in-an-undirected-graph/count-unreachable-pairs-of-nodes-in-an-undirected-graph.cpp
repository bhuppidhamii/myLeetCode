class Solution {
public:
    vector<int> rank;
    vector<int> parent;
    int find(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y) {
        int x_p = find(x);
        int y_p = find(y);
        if (x_p == y_p)
            return;

        if (rank[x_p] > rank[y_p]) {
            parent[y_p] = x_p;
        } else if (rank[y_p] > rank[x_p]) {
            parent[x_p] = y_p;
        } else {
            parent[y_p] = x_p;
            rank[x_p] += 1;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (auto& e : edges) {
            int x = e[0];
            int y = e[1];
            Union(x, y);
        }
        unordered_map<int, int> mp;
        for (auto& p : parent) {
            mp[find(p)]++;
        }

        long long remNodes = n;
        long long count = 0;
        for (auto& i : mp) {
            long long size = i.second;
            count += (size * (remNodes - size));
            remNodes -= size;
        }
        return count;
    }
};