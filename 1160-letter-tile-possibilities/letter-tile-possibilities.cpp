class Solution {
public:
    int count;
    void solve(vector<int>& v) {
        count++;

        for (int i = 0; i < 26; i++) {
            if (v[i] == 0) {
                continue;
            }

            v[i]--;
            solve(v);
            v[i]++;
        }
    }
    int numTilePossibilities(string tiles) {
        vector<int> v(26, 0);
        for (auto& ch : tiles) {
            v[ch - 'A']++;
        }
        count = 0;
        solve(v);
        return count - 1;
    }
};