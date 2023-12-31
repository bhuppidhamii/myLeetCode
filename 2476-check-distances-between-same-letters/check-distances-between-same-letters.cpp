class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map<char, int> m;
        int N = s.size();
        for (int i = 0; i < N; i++) {
            int dist = 0;
            if (m.find(s[i]) != m.end()) {
                dist = max(dist, i - m[s[i]] - 1);
                if (distance[s[i] - 'a'] != dist) {
                    return false;
                }
            } else {
                m[s[i]] = i;
            }
        }
        return true;
    }
};