class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        int N = s.size();
        for (int i = 0; i < N; i++) {
            int lst = s.find_last_of(s[i]);
            int dist = lst - i - 1;
            if (lst != i) {
                if (dist != distance[s[i] - 'a']) {
                    return false;
                }
            }
        }
        return true;
    }
};